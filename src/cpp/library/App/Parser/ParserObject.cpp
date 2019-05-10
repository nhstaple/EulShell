#include "./ParserObject.h"
#include "./EulerInterface/EulerInterface.h"

void Command::printObject()
{
    cout << "\n> \t * ";
    cout << this->cmd << "\t | ";
    for(string alt : this->alts) {
        cout << alt;
        if(alt != this->alts.back()) { cout << ", "; }
    }
    if(this->description.size()) {
        cout << "\n> \t " << "  " + this->description;
    }
    if(this->params && this->params->getInterfaceCopy().size() > 0) {
        cout << "\n> \t " << "  " << "Parameters";
        params->paramPrint();
    }
}

Command::Command(string str)
{
    cmd = str;
    params = new EulerInterface;
}

Command::Command()
{
    params = new EulerInterface;
}

Command::~Command()
{
    //if(params)
      //  delete params;
}

ParsedCommand::ParsedCommand()
{
    this->input = new EulerInterface;
    this->problem = nullptr;
}

ParsedCommand::~ParsedCommand()
{
    if(input)
        delete input;
}

void ParsedCommand::printObject()
{
    cout << "Parsed cmd -> " + command;
}

void ParsedCommand::operator=(const ParsedCommand& cmd)
{
      this->command = cmd.command;
      this->problem = cmd.problem;
      if(input) { delete input; }
      vector<InterfaceAtom> data;
      EulerInterface copy = cmd.input->getInterfaceCopy();
      for(InterfaceAtom a : copy.getInterfaceCopy()) {
          data.push_back(a);
      }
      this->input = new EulerInterface(data);
}
