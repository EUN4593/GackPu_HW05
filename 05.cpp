#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 도형 클래스의 기본 인터페이스
class Shape {
public:
    virtual string getName() const = 0;
    virtual ~Shape() {}
};

// 선 클래스
class Line : public Shape {
public:
    string getName() const override {
        return "Line";
    }
};

// 원 클래스
class Circle : public Shape {
public:
    string getName() const override {
        return "Circle";
    }
};

// 사각형 클래스
class Rectangle : public Shape {
public:
    string getName() const override {
        return "Rectangle";
    }
};

// 그래픽 편집기 클래스
class GraphicEditor {
private:
    vector<Shape*> shapes;

public:
    ~GraphicEditor() {
        for (Shape* shape : shapes) {
            delete shape;
        }
    }

    void insertShape() {
        cout << "선:1, 원:2, 사각형:3 >> ";
        int choice;
        cin >> choice;

        Shape* newShape = nullptr;
        switch (choice) {
        case 1:
            newShape = new Line();
            break;
        case 2:
            newShape = new Circle();
            break;
        case 3:
            newShape = new Rectangle();
            break;
        default:
            cout << "잘못된 선택입니다.\n";
            return;
        }

        shapes.push_back(newShape);
        cout << newShape->getName() << " 삽입 완료.\n";
    }

    void deleteShape() {
        if (shapes.empty()) {
            cout << "삭제할 도형이 없습니다.\n";
            return;
        }

        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        int index;
        cin >> index;

        if (index < 0 || index >= shapes.size()) {
            cout << "잘못된 인덱스입니다.\n";
            return;
        }

        delete shapes[index];
        shapes.erase(shapes.begin() + index);
        cout << "도형 삭제 완료.\n";
    }

    void showAllShapes() const {
        if (shapes.empty()) {
            cout << "저장된 도형이 없습니다.\n";
            return;
        }

        for (size_t i = 0; i < shapes.size(); ++i) {
            cout << i << ": " << shapes[i]->getName() << endl;
        }
    }

    void run() {
        while (true) {
            cout << "그래픽 에디터입니다.\n";
            cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
            int command;
            cin >> command;

            switch (command) {
            case 1:
                insertShape();
                break;
            case 2:
                deleteShape();
                break;
            case 3:
                showAllShapes();
                break;
            case 4:
                cout << "프로그램을 종료합니다.\n";
                return;
            default:
                cout << "잘못된 명령입니다.\n";
            }
        }
    }
};

int main() {
    GraphicEditor editor;
    editor.run();
    return 0;
}
