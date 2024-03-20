int main()
{
    LinkedList list;

    int n;
    cout << "Enter number of terms : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number : ";
        list.insert(i);
    }
    list.print();

    char x;
    int a, b, f, d, pos, j; // Declare variables for user input
    do
    {
        cout << "s. Search"
             << "\n";
        cout << "c. count duplicates"
             << "\n";
        cout << "r. remove duplicates"
             << "\n";
        cout << "i. insert"
             << "\n";
        cout << "e. exit"
             << "\n";

        cout << "Enter your choice: ";
        cin >> x;

        switch (x)
        {
        case 's':
            cout << "Enter number to search : ";
            cin >> a;
            int j = list.search(a);
            cout << "\n"
                 << j << "\n"; // Print the search result
            break;

        case 'c':
            cout << "Enter number to count duplicates : ";
            cin >> b;
            list.count_duplicates(b);
            break;

        case 'r':
            cout << "Enter number to remove duplicates : ";
            cin >> f;
            list.remove_duplicates(f);
            list.print();
            break;

        case 'i':
            cout << "Enter number and index to insert : ";
            cin >> d >> pos;
            list.insert_pos(d, pos);
            cout << "\n";
            list.print();
            break;

        case 'e':
            exit(0); // Properly exit the program
            break;

        default:
            cout << "Wrong entry..Retry";
            break;
        }

    } while (x != 'e');