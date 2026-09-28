#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }


    void insertBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        count++;
    }


    void insertEnd(string song) {
        Node* newNode = new Node(song);

        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
    }


    void insertAfter(string target, string newSong) {
        Node* current = head;


        while (current != nullptr &&
               current->song != target) {
            current = current->next;
        }


        if (current == nullptr) {
            cout << "Song " << target
                 << " not found. Insertion not possible."
                 << endl;
            return;
        }

        Node* newNode = new Node(newSong);


        newNode->next = current->next;
        newNode->prev = current;


        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        else {

            tail = newNode;
        }

        current->next = newNode;

        count++;
    }


    void removeFirst() {
        if (head == nullptr) {
            cout << "Playlist is empty. Cannot remove song."
                 << endl;
            return;
        }

        Node* temp = head;


        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        count--;
    }


    int size() {
        return count;
    }


    void display() {
        if (head == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* current = head;

        cout << "Playlist: ";

        while (current != nullptr) {
            cout << current->song;

            if (current->next != nullptr)
                cout << " -> ";

            current = current->next;
        }

        cout << endl;
        cout << "Number of songs: " << count << endl;
    }


    ~Playlist() {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    Playlist playlist;

    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int choice;

        cout << "\n1. Add song at beginning";
        cout << "\n2. Add song at end";
        cout << "\n3. Insert song after a specific song";
        cout << "\n4. Remove first song";
        cout << "\n5. Count songs";
        cout << "\n6. Display playlist";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string song;

            cout << "Enter song name: ";
            cin >> song;

            playlist.insertBeginning(song);
            playlist.display();
        }

        else if (choice == 2) {
            string song;

            cout << "Enter song name: ";
            cin >> song;

            playlist.insertEnd(song);
            playlist.display();
        }

        else if (choice == 3) {
            string target, newSong;

            cout << "Enter song after which to insert: ";
            cin >> target;

            cout << "Enter new song: ";
            cin >> newSong;

            playlist.insertAfter(target, newSong);
            playlist.display();
        }

        else if (choice == 4) {
            playlist.removeFirst();
            playlist.display();
        }

        else if (choice == 5) {
            cout << "Number of songs: "
                 << playlist.size() << endl;
        }

        else if (choice == 6) {
            playlist.display();
        }

        else {
            cout << "Invalid operation!" << endl;
        }
    }

    return 0;
}
