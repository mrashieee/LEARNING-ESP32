float grades[25];
int br = 115200;
String Prompt;
int numGrades;
int i;
int j;
float tempGrade;
float sumGrades;
float averageGrade;
int highestGrade;
int lowestGrade;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  inputGrades();
  gradeSort();
  averageGrades();
  highGrade();
  lowGrade();
}

void inputGrades() {
  Serial.println("How many grades did you get?");
  while (Serial.available() == 0) {

  }
  numGrades = Serial.parseInt();
  clearSerial();
  for (i=0;i<numGrades;i++) {
    Prompt = "Please Input Your Grade: "+String(i+1);
    Serial.println(Prompt);
    while (Serial.available() == 0) {

    }
    grades[i] = Serial.parseFloat();
    clearSerial();
  }
  Serial.println("Your grades are: ");
  for (i=0;i<numGrades;i++) {
    Serial.println(grades[i]);
  }
}

void clearSerial() {
  if (Serial.available()) {
    Serial.read();
  }
}
void gradeSort() {
  Serial.println("Sorting your list of grades(Ascending Order): ");
  for (i=0;i<numGrades-1;i++) {
    for (j=0;j<numGrades-1-i;j++) {
      if (grades[j]>grades[j+1]) {
        tempGrade = grades[j];
        grades[j] = grades[j+1];
        grades[j+1] = tempGrade;
      }
    }
  }
  for (i=0;i<numGrades;i++) {
    Serial.println(grades[i]);
  }
  Serial.println("Sorting your list of grades(Descending Order): ");
  for (i=0;i<numGrades-1;i++) {
    for (j=0;j<numGrades-1-i;j++) {
      if (grades[j]<grades[j+1]) {
        tempGrade = grades[j];
        grades[j] = grades[j+1];
        grades[j+1] = tempGrade;
      }
    }
  }
  for (i=0;i<numGrades;i++) {
    Serial.println(grades[i]);
  }
}

void averageGrades() {
  sumGrades=0;
  for (i=0;i<numGrades;i++) {
    sumGrades+=grades[i];
  }
  averageGrade = sumGrades/numGrades;
  Prompt = "Average Grade is: " + String(averageGrade);
  Serial.println(Prompt);
}

void highGrade() {
  highestGrade = 0;
  for (i=0;i<numGrades;i++) {
    if (highestGrade < grades[i]) {
      highestGrade=grades[i];
    }
  }
  Serial.println("Your highest score is: "+String(highestGrade));
}

void lowGrade() {
  lowestGrade = highestGrade;
  for (i=0;i<numGrades;i++) {
    if (lowestGrade > grades[i]) {
      lowestGrade=grades[i];
    }
  }
  Serial.println("Your lowest score is: "+String(lowestGrade));
}