//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Command/Invert.hpp"
#include "Command/Replace.hpp"
#include "Command/ToGreyScale.hpp"
#include "Command/Fill.hpp"
#include "Command/H_Mirror.hpp"
#include "Command/V_Mirror.hpp"
#include "Command/Add.hpp"
#include "Command/Move.hpp"
#include "Command/Slide.hpp"
#include "Command/Crop.hpp"
#include "Command/Resize.hpp"
#include "Command/R_Left.hpp"
#include "Command/R_Right.hpp"
#include "Command/ScaleUp.hpp"

#include "Logger.hpp"
#include "Command/Chain.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        // TODO: implement cases for the new commands

        if (command_name == "invert") {
            return new command::Invert();
        }

        if (command_name == "to_gray_scale") {
            return new command::ToGreyScale();
        }

        if (command_name == "replace") {
            Color from, to;
            input >> from >> to;
            return new command::Replace(from, to);
        }

        if (command_name == "fill") {
            int x, y, width, height;
            Color color;
            input >> x >> y >> width >> height >> color;
            return new command::Fill(x, y, width, height, color);;
        }

        if(command_name == "h_mirror") {
            return new command::H_Mirror();
        }

        if(command_name == "v_mirror") {
            return new command::V_Mirror();
        }

        if(command_name == "add") {
            std::string filename;
            Color neutral;
            int x, y;
            input >> filename >> neutral >> x >> y;
            return new command::Add(filename, neutral, x, y);
        }

        if(command_name == "move") {
            int x, y;
            if(!(input >> x >> y))
                return nullptr;

            Color fill;
            if(input >> fill) {
                return new command::Move(x, y, fill);
            }

            input.clear();
            return new command::Move(x, y);
        }

        if(command_name == "slide"){
            int x, y;
            input >> x >> y;
            return new command::Slide(x, y);
        }

        if(command_name == "crop"){
            int x, y, width, height;
            input >> x >> y >> width >> height;
            return new command::Crop(x, y, width, height);
        }

        if(command_name == "resize"){
            int x, y, width, height;
            input >> x >> y >> width >> height;
            return new command::Resize(x, y, width, height);
        }

        if(command_name == "rotate_left"){
            return new command::R_Left();
        }

        if(command_name == "rotate_right"){
            return new command::R_Right();
        }

        if(command_name == "scaleup" || command_name == "scale_up"){
            int x;
            int y;
            input >> x >> y;
            return new command::ScaleUp(x, y);
        }

        if(command_name == "chain"){
            std::vector<std::string> scrims;
            std::string token;

            while(input >> token && token != "end"){
                scrims.push_back(token);
            }

            if (!input.eof() && token != "end") {
                *Logger::err() << "Malformed chain command\n";
                return nullptr;
            }

            return new command::Chain(scrims);
        }

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
