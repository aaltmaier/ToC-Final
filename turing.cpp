#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct action {
    int dir, move;
    bool accept;
    char read, edit;
    action(char r, char e, int m, int d, bool a) {
        read = r; edit = e; move = m; dir = d; accept = a;
    }
};

struct node {
    vector<action> actions;
};

bool turingMachine(vector<node> n, string s, int accept_state) {
    int state = 0;      // holds the state
    int reading = 1;    // holds the character we are currently reading
    
    for(int actI = 0; actI < n[state].actions.size(); actI++) {
        if(n[state].actions[actI].read == s[reading]) {
            // now reading the character
            cout << "Reading " << n[state].actions[actI].read << endl;
            
            // edit the character
            s[reading] = n[state].actions[actI].edit;
            
            // change the head
            reading += (int) n[state].actions[actI].dir;
            
            // move to the appropriate state
            state = n[state].actions[actI].move;
            
            // print relevant information
            cout << "  State  -> " << state << endl;
            cout << "  Head   -> " << s[reading] << endl;
            cout << "  String -> " << s << endl;
            
            // reset the state counter
            actI = -1;
            
            // check if we're in an accept state
            if( state == accept_state ) { return true; }
        }
    }
    return false;
}

int main()
{
    string input_str;
    cout << "Enter the name of the file to read from: " << endl;
    cin >> input_str;
    ifstream infile(input_str);

    //number of nodes/states
    int size;
    infile >> size;
    vector<node> nodes(size);

    int accept_state;
    infile >> accept_state;
    
    int d, s, m;
    bool a;
    char r ,e;
    
    /*
     * s = state index, r = char reading from tape string
     * e = what to edit current reading to
     * m = which state index to move to
     * d = direction to move head on tape string, -1 = left, 0 = stay, 1 = right
     * a = if state is accept state
     * accept_state = the TM's accept state
     */
    
    while(infile >> s >> r >> e >> m >> d >> a) {
        nodes[s].actions.push_back(action(r, e, m, d, a));
    }
    
    infile.close();
    
    string str;
    cout << "Please enter your input string and then press enter: " << endl;
    cin >> str;
    
    if(turingMachine(nodes, str, accept_state)) { cout << "ACCEPT" << endl; }
    else { cout << "REJECT" << endl; }
    
    return 0;
}
