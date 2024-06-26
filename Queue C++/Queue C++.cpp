#include <iostream>
using namespace std;

class queues
{
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
    queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //CEK APAKAH ANTRIAN PENUH
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        //CEK APAKAH ANTRIAN KOSONG
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            // JIKA REAR BERADA DI POSISI TERAKHIR ARRAY, KEMBALI KE AWAL ARRAY
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;

        }
        queue_array[REAR] = num;
        
    }

    void remove()
    {
        //CEK APAKAH ANTRIAN KOSONG
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe deleted from the queue is: " << queue_array[FRONT] << "\n";

        //CEK JIKA ANTRIAN HANYA MEMILIKI SATU ELEMENT
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // JIKA ELEMEN YANG DIHAPUS BERADA DI POSISI TERAKHIR ARRAY,KEMBALI KE AWAL ARRAY
            if (FRONT == max - 1)
                FRONT = 0;
            else 
                FRONT = FRONT + 1;

        }
    }

    void display()
    {

        int FRONT_Position = FRONT;
        int REAR_Position = REAR;


        // CEK APAKAH ANTRIAN KOSOSNG
        if (FRONT_Position == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElement in the Queue are...\n";

        // JIKA FRONT <= REAR, ITERASI DARI FRONT HINGGA REAR
        if (FRONT_Position <= REAR_Position)
        {
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << "  ";
                FRONT_Position++;
            }
            cout << endl;
        }

        else
        {
            // JIKA FRONT > REAAR ITERASI DARI FRONT HINGGA AKHIR ARRAY
            while (FRONT_Position <= max - 1)
            {
                cout << queue_array[FRONT_Position] << "  ";
                FRONT_Position++;
            }
            FRONT_Position = 0;

            //ITERASI DARI AWAL ARRAY HINGGA REAR
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << "  ";
                FRONT_Position++;
            }
            cout << endl;
        }
    }

};

int main()
{
    queues q;
    char ch;

    while (true)
    {
        try 
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display Values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }

            default:
            {
                cout << "Invalid Option!!" << endl;
                break;
            }

            }
        }
        catch (exception& e)
        {
            cout << "Check for the Values entered." << endl;
        }
    }
    return 0;

}
