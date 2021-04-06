int main() {
  /*This program uses the system function to execute another program and print its own code. */
  system("gcc -o printCode C:\\Users\\agbod\\GitHub\\20201034_CPrograms2\\printCode.c");
  system("printCode C:\\Users\\agbod\\GitHub\\20201034_CPrograms2\\sys.c");
  return 0;
}
