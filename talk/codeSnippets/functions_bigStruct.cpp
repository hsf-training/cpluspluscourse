struct BigStruct {...};
BigStruct s;

// parameter by value
void printBS(BigStruct p) {
  ...
}
printBS(s); // copy

// parameter by reference
void printBSp(BigStruct &q) {
  ...
}
printBSp(s); // no copy
