#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

struct state;
struct transition;

struct state {
	vector<transition> transitions;
};

struct transition {
	char next_state;
	char read;
	char replace;
	int direction;
	transition(char new_s, char r, char rep, int dir) {
		next_state = new_s; read = r; replace = rep; direction = dir;
	}
};

bool check_match(state A, state B, state C, state D, state E, state F, state G, stack<char> data_stack, vector<char> data_vector, char last_stack_entry, char last_vec_entry) {
	char current_stack_top = data_stack.top();
	char current_vec_top = data_vector.back();
	cout << "Current stack top: " << current_stack_top << endl;
	cout << "Current vector top: " << current_vec_top << endl;

	if (current_stack_top == '^') { return true; }

	if (current_stack_top == current_vec_top) {
		data_stack.pop();
		data_vector.pop_back();
		return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
	}

	switch (current_stack_top) { // Next value in data_stack is a State character
		case 'A': cout << "State A" << endl;
		data_stack.pop(); // Remove current state from the stack
		current_stack_top = data_stack.top(); // Re-assign stack top value
		for (int i = 0; i < A.transitions.size(); i++) {
			if (A.transitions[i].read == current_stack_top) {
				if (A.transitions[i].direction == -1) { // Moving Left on tape
					cout << "Head moving left, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(A.transitions[i].replace);
					data_stack.push(last_stack_entry);
					data_stack.push(A.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, '*', '*');
				}
				if (A.transitions[i].direction == 0) { // Staying on tape
					cout << "Head staying, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(A.transitions[i].replace);
					data_stack.push(A.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
				if (A.transitions[i].direction == 1) { // Moving Right on tape
					cout << "Head moving right, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(A.transitions[i].next_state);
					data_stack.push(A.transitions[i].replace);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
			}
		}
		break;

		case 'B': cout << "State B" << endl;
		data_stack.pop(); // Remove current state from the stack
		current_stack_top = data_stack.top(); // Re-assign stack top value
		for (int i = 0; i < B.transitions.size(); i++) {
			if (B.transitions[i].read == current_stack_top) {
				if (B.transitions[i].direction == -1) { // Moving Left on tape
					cout << "Head moving left, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(B.transitions[i].replace);
					data_stack.push(last_stack_entry);
					data_stack.push(B.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, '*', '*');
				}
				if (B.transitions[i].direction == 0) { // Staying on tape
					cout << "Head staying, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(B.transitions[i].replace);
					data_stack.push(B.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
				if (B.transitions[i].direction == 1) { // Moving Right on tape
					cout << "Head moving right, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(B.transitions[i].next_state);
					data_stack.push(B.transitions[i].replace);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
			}
		}
		break;

		case 'C': cout << "State C" << endl;
		data_stack.pop(); // Remove current state from the stack
		current_stack_top = data_stack.top(); // Re-assign stack top value
		for (int i = 0; i < C.transitions.size(); i++) {
			if (C.transitions[i].read == current_stack_top) {
				if (C.transitions[i].direction == -1) { // Moving Left on tape
					cout << "Head moving left, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(C.transitions[i].replace);
					data_stack.push(last_stack_entry);
					data_stack.push(C.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, '*', '*');
				}
				if (C.transitions[i].direction == 0) { // Staying on tape
					cout << "Head staying, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(C.transitions[i].replace);
					data_stack.push(C.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
				if (C.transitions[i].direction == 1) { // Moving Right on tape
					cout << "Head moving right, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(C.transitions[i].next_state);
					data_stack.push(C.transitions[i].replace);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
			}
		}
		break;

		case 'D': cout << "State D" << endl;
		data_stack.pop(); // Remove current state from the stack
		current_stack_top = data_stack.top(); // Re-assign stack top value
		for (int i = 0; i < D.transitions.size(); i++) {
			if (D.transitions[i].read == current_stack_top) {
				if (D.transitions[i].direction == -1) { // Moving Left on tape
					cout << "Head moving left, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(D.transitions[i].replace);
					data_stack.push(last_stack_entry);
					data_stack.push(D.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, '*', '*');
				}
				if (D.transitions[i].direction == 0) { // Staying on tape
					cout << "Head staying, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(D.transitions[i].replace);
					data_stack.push(D.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
				if (D.transitions[i].direction == 1) { // Moving Right on tape
					cout << "Head moving right, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(D.transitions[i].next_state);
					data_stack.push(D.transitions[i].replace);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
			}
		}
		break;

		case 'E': cout << "State E" << endl;
		data_stack.pop(); // Remove current state from the stack
		current_stack_top = data_stack.top(); // Re-assign stack top value
		for (int i = 0; i < E.transitions.size(); i++) {
			if (E.transitions[i].read == current_stack_top) {
				if (E.transitions[i].direction == -1) { // Moving Left on tape
					cout << "Head moving left, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(E.transitions[i].replace);
					data_stack.push(last_stack_entry);
					data_stack.push(E.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, '*', '*');
				}
				if (E.transitions[i].direction == 0) { // Staying on tape
					cout << "Head staying, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(E.transitions[i].replace);
					data_stack.push(E.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
				if (E.transitions[i].direction == 1) { // Moving Right on tape
					cout << "Head moving right, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(E.transitions[i].next_state);
					data_stack.push(E.transitions[i].replace);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
			}
		}
		break;

		case 'F': cout << "State F" << endl;
		data_stack.pop(); // Remove current state from the stack
		current_stack_top = data_stack.top(); // Re-assign stack top value
		for (int i = 0; i < F.transitions.size(); i++) {
			if (F.transitions[i].read == current_stack_top) {
				if (F.transitions[i].direction == -1) { // Moving Left on tape
					cout << "Head moving left, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(F.transitions[i].replace);
					data_stack.push(last_stack_entry);
					data_stack.push(F.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, '*', '*');
				}
				if (F.transitions[i].direction == 0) { // Staying on tape
					cout << "Head staying, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(F.transitions[i].replace);
					data_stack.push(F.transitions[i].next_state);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
				if (F.transitions[i].direction == 1) { // Moving Right on tape
					cout << "Head moving right, reading " << current_stack_top << endl;
					data_stack.pop();
					data_stack.push(F.transitions[i].next_state);
					data_stack.push(F.transitions[i].replace);
					return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
				}
			}
		}
		break;

		case 'G': cout << "State G" << endl;
		// Check current_stack_top, pick the correct transition based on that; apply transition
		break;
	}

	if (current_vec_top == 'A' || current_vec_top == 'B' || current_vec_top == 'C' || current_vec_top == 'D' || current_vec_top == 'E' || current_vec_top == 'F' || current_vec_top == 'G') {
		cout << "Read a state from the data vector... " << endl;
		data_stack.pop();
		// data_vector.pop_back();
		return check_match(A, B, C, D, E, F, G, data_stack, data_vector, current_stack_top, current_vec_top);
	}

	return false;

}

int main() {
	// Set up TM states and their transitions
	state A;
	state B;
	state C;
	state D;
	state E;
	state F;
	state G;

	transition A1('B', '1', '1', -1); A.transitions.push_back(A1);
	transition A2('C', '0', '$', 1); A.transitions.push_back(A2);
	transition A3('G', '*', '*', 0); A.transitions.push_back(A3);
	
	transition B1('B', '$', '0', -1); B.transitions.push_back(B1);
	transition B2('A', '*', '*', 1); B.transitions.push_back(B2);
	
	transition C1('C', '0', '0', 1); C.transitions.push_back(C1);
	transition C2('D', '1', '1', 1); C.transitions.push_back(C2);

	transition D1('D', '1', '1', 1); D.transitions.push_back(D1);
	transition D2('E', '*', '*', -1); D.transitions.push_back(D2);

	transition E1('F', '1', '*', -1); E.transitions.push_back(E1);

	transition F1('F', '1', '1', -1); F.transitions.push_back(F1);
	transition F2('F', '0', '0', -1); F.transitions.push_back(F2);
	transition F3('A', '$', '$', 1); F.transitions.push_back(F3);

	// Begin test cases
	// First case: a state appears first in the data stack, e.g. the head is moving right

	stack<char> data_stack;
	string stack_str = "^**1100A$*"; // Reversed c1 with end-of-stack marker "^"; c1 = *$A0011**
	for (char& c : stack_str) {
		data_stack.push(c);
	}
	vector<char> data_vector;
	string vector_str = "^**110C$$*"; // reversed c2 with end-of-stack marker "^"; c2 = *$$C011**
	for (char& c : vector_str) {
		data_vector.push_back(c);
	}

	if (check_match(A, B, C, D, E, F, G, data_stack, data_vector, '*', '*')) { cout << "States match!" << endl << endl; }
	else { cout << "States don't match..." << endl; }


	// Second case: a state appears first in the data vector, e.g. the head is moving left
	stack<char> data_stack_2;
	string stack_str_2 =  "^**1E10$$*"; // *$$01E1**
	for (char& c : stack_str_2) {
		data_stack_2.push(c);
	}
	vector<char> data_vector_2;
	string vector_str_2 = "^***1F0$$*"; // *$$0F1***
	for (char& c : vector_str_2) {
		data_vector_2.push_back(c);
	}

	if (check_match(A, B, C, D, E, F, G, data_stack_2, data_vector_2, '*', '*')) { cout << "Second case states match!" << endl << endl; }
	else { cout << "Second case states don't match..." << endl; }


	// Third case: The state appears at the same time in both the data vector and the data stack, e.g. the head is staying in place

	stack<char> data_stack_3;
	string stack_str_3 = "^****$$$*A"; // A*$$$****
	for (char& c : stack_str_3) {
		data_stack_3.push(c);
	}
	vector<char> data_vector_3;
	string vector_str_3 = "^****$$$*G"; // G*$$$****
	for (char& c : vector_str_3) {
		data_vector_3.push_back(c);
	}

	if (check_match(A, B, C, D, E, F, G, data_stack_3, data_vector_3, '*', '*')) { cout << "Third case states match!" << endl; }
	else { cout << "Third case states don't match..." << endl; }


}







