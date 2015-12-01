

ConsoleCoord ConsoleCoord::operator+(const ConsoleCoord& cc)
{
	return ConsoleCoord(cc.line + line, cc.column + column);
}

ConsoleCoord ConsoleCoord::operator+(const Size& cc)
{
	return ConsoleCoord(cc.line + line, cc.column + column);
}
