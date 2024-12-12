#include <iostream>
#include <fstream>
#include "json.hpp"
#include <sstream>

using namespace std;
using json::JSON;

void nullIfEmpty(JSON &queue) {
        if (queue.JSONType() == JSON::Class::Array && queue.length() == 0) {
                queue = JSON(nullptr);
        }
}

JSON loadJSON(const string &fname) {
        ifstream file(fname);
        if (!file.is_open()) {
                return JSON::Make(JSON::Class::Array);
        }
        stringstream ss;
        ss << file.rdbuf();

        string content = ss.str();
        file.close();
        return JSON::Load(content);
}

void saveJSON(const string &filename, JSON &data) {
        nullIfEmpty(data);
        ofstream file(filename);
        if (file.is_open()) {
                file << data.dump();
        }
    
        file.close();
}

void addPerson(const string &filename, JSON &queue, const string &firstName,
                const string &lastName, const string &email) {
        for (auto &entry : queue.ArrayRange()) {
                if (entry["email"].ToString() == email) {
                        cout << "Person already in queue\n"; 
                        return;
                }
        }

        JSON person;
        person["email"] = email;
        person["firstName"] = firstName;
        person["lastName"] = lastName;
        queue.append(person);
        saveJSON(filename, queue);
//        cout << "Person added to queue\n";
}

void removePerson(const string &filename, JSON &queue) {
        if (queue.JSONType() == JSON::Class::Array && queue.length() > 0) {
                JSON newQueue = JSON::Make(JSON::Class::Array);
                for (int i = 1; i < queue.length(); i++) {
                        newQueue.append(queue[i]);
                }
                queue = newQueue;
//                cout << "Head removed from queue.\n";
        } else {
                // cout << "empty queue\n";
        }
        saveJSON(filename, queue);
}

void clearQueue(const string &filename, JSON &queue) {
        queue = JSON::Make(JSON::Class::Array);
        saveJSON(filename, queue);
//        cout << "Queue cleared\n";
}

int main(int argc, char* argv[]) {
        if (argc < 3) {
                cerr << "Usage: ./PA09 <filename> <command> [arguments...]\n";
                return 1;
        }
        string fname = argv[1];
        string command = argv[2];

        JSON queue = loadJSON(fname);
        if (command == "add") {
                if (argc != 6) {
                        cerr << "Usage: ./PA09 <filename> add <firstName>" <<
                                " <lastName> <email>\n";
                        return 1;
                }
                string firstName = argv[3];
                string lastName = argv[4];
                string email = argv[5];
                addPerson(fname, queue, firstName, lastName, email);
        } else if (command == "remove") {
                removePerson(fname, queue);
        } else if (command == "clear") {
                clearQueue(fname, queue);
        } else {
//                cout << "Unknown command\n";
                return 1;
        }

        return 0;
}
