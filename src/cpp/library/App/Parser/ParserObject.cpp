#include "./ParserObject.h"
#include "./EulerInterface/EulerInterface.h"

void Command::printObject()
{
    cout << "> \t * ";
    cout << this->cmd << "\t : ";
    int i = 0;
    for(string alt : this->alts) {
        cout << alt;
        if(alt != this->alts.back()) { cout << ", "; }
    }
    if(description.size()) {
        cout << "\n> \t ->" + description + "\n>\n";
    } else {
        cout << "\n>\n";
    }
}

ParsedCommand::ParsedCommand()
{
    this->input = new EulerInterface;
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
