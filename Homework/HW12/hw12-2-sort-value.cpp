/*
    สร้าง Struct เพื่อเก็บข้อมูลของคน 4 คน โดยเก็บข้อมูล ชื่อ , อายุ , เพศ และคะแนนสะสม และแสดงผลออกมาบนหน้าจอ
    
    Test case:
        Student A
        Name : 
            Yorn
        Score : 
            21.42

        Student B
        Name : 
            Omen
        Score : 
            56.00

        Student C
        Name : 
            Alice
        Score : 
            80.75

        Student D
        Name : 
            Violet
        Score : 
            67.76

    Output:
        Alice Violet Omen Yorn
        80.75 67.76 56.00 21.42

    Test case:
        Student A
        Name : 
            Payna
        Score : 
            77.77
            
        Student B
        Name : 
            Zanis
        Score : 
            88.88

        Student C
        Name : 
            Lubu
        Score : 
            66.66

        Student D
        Name : 
            Krixi
        Score : 
            99.99

    Output:
        Krixi Zanis Payna Lubu
        99.99 88.88 77.77 66.66

*/
  #include <stdio.h>
  #include <string.h>

// สร้างโครงสร้างข้อมูล Student
struct Student {
    char name[50];
    int age;
    char gender;
    float score;
};

int main() {
    struct Student students[4]; // สร้างอาร์เรย์ของ struct Student มี 4 สมาชิก

    // รับข้อมูลสำหรับ Student A, B, C, และ D
    for (int i = 0; i < 4; i++) {
        printf("Student %c\n", 'A' + i);
        printf("Name : ");
        scanf("%s", students[i].name);
        printf("Score : ");
        scanf("%f", &students[i].score);
        printf("\n");
    }

    // เรียงลำดับข้อมูลตามคะแนนสะสมจากมากไปน้อย
    for (int i = 0; i < 4 - 1; i++) {
        for (int j = 0; j < 4 - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                // สลับข้อมูลของนักเรียน j และ j+1
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // แสดงผลลัพธ์
    printf("Output:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s ", students[i].name);
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
        printf("%.2f ", students[i].score);
    }
    printf("\n");

    return 0;
}
