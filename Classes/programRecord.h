
class ProgramRecord
{
  protected:
    ofstream out;
    ifstream in;
    fstream finout;
    Program program;
    string fileName = "Records/Program.dat";

  public:
    void Display_Program()
    {
        in.open(fileName.c_str(), ios::binary);
        while (in.read((char *)&program), sizeof(program)))
            {
                program.Display();
            }
        in.close();
    }

    void Enter_Program()
    {
        out.open(fileName.c_str(), ios::binary | ios::app);
        program.Enter();
        out.write((char *)&program, sizeof(program));
        out.close();
    }

    Program Find_Program(long long int n)
    {
        in.open(fileName.c_str(), ios::binary);
        int found = 0;
        while (in.read((char *)&program, sizeof(program)))
        {
            if (program.getProgramID() == n)
            {
                in.close();
                found = 1;
                return program;
            }
        }
        in.close();
    }

    void Delete_Program(long long int n)
    {
        in.open(fileName.c_str(), ios::binary);
        out.open("Records/Temp.dat", ios::out | ios::binary);
        while (in.read((char *)&program, sizeof(program)))
        {
            if (program.getProgramID() != n)
            {
                out.write((char *)&program, sizeof(program));
            }
        }
        in.close();
        out.close();
        remove(fileName.c_str());
        rename("Records/Temp.dat", fileName.c_str());
    }

    void Update_Program(long long int n)
    {
        finout.open(fileName.c_str(), ios::binary | ios::in | ios::out);
        int found = 0;
        while (finout.read((char *)&program, sizeof(program)))
        {
            if (program.getProgramID() == n)
            {
                program.Display();
                long long int pos = -1 * sizeof(program);
                finout.seekp(pos, ios::cur);
                cout << "\n\n\n\n\n\n\n\n\n\n\n";
                cout << "\t\t||------------------------------------------------||\n";
                cout << "\t\t     Enter the new details of Program\n";
                cout << "\t\t||------------------------------------------------||\n";
                cout << "\n\n";
                program.Enter();
                finout.write((char *)&program, sizeof(program));
            }
        }
        finout.close();
    }
};