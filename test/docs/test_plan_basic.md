#Intro
Basic group of class are data centric class. Their basic function is to host data, thus they are easy to test. 
Basic classes rely only on classes within basic class group or c++ standard library. 

##Size
Size::Size(int aLine, int aColumn)
* input: Size(-1, 1)
* output: error

* input: Size()
* output: normal

void Size::verify()
*test internally*


##Coord
Coord::Coord()
Coord::Coord(int aLine, int aColumn)
*test internally*

Coord Coord::CoordXY(int xx, int yy)
* input: CoordXY(-1, 1)
* output: 1, -1

Coord Coord::operator+(const Size& cc)
* input: Coord(-1, 1) + Size(1, 1)
* output: Coord(0, 2)

Coord Coord::operator+(const Coord& cc)
* input: Coord() + Coord(1, 1)
* output: Coord(1, 1)

bool Coord::operator==(const Coord& cc)
*test internally*

Coord Coord::operator-(const Coord& cc)
Coord Coord::operator*(int nn)
Coord Coord::operator/(int nn)
*can wait*


##ConsoleCoord
Coord(int line = MIN_LINES, int column = MIN_LINES);
* input: ConsoleCoord(-1, 2)
* output: error

* input: ConsoleCoord(25, 2)
* output: error

void setLine(int line);
void setColume(int column);
*test internally*

ConsoleCoord operator+(const ConsoleCoord& cc);
ConsoleCoord operator+(const Size& cc);
*can wait*

##PrintJob
* input: PrintJob( ConsoleCoord(23, 50), 'a')
* output: normal

##ImageLoader
vector<string> ImageLoader::load(const string& fileName)
* input: graph/moon.txt
* output: "1234", "4321"

vector<vector<string> > ImageLoader::loadBatch(const string& fileName)
* input: batch/moon_batch.txt
* output: "1234", "4444", "4321"
