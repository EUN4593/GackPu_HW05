#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ���� Ŭ������ �⺻ �������̽�
class Shape {
public:
    virtual string getName() const = 0;
    virtual ~Shape() {}
};

// �� Ŭ����
class Line : public Shape {
public:
    string getName() const override {
        return "Line";
    }
};

// �� Ŭ����
class Circle : public Shape {
public:
    string getName() const override {
        return "Circle";
    }
};

// �簢�� Ŭ����
class Rectangle : public Shape {
public:
    string getName() const override {
        return "Rectangle";
    }
};

// �׷��� ������ Ŭ����
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
        cout << "��:1, ��:2, �簢��:3 >> ";
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
            cout << "�߸��� �����Դϴ�.\n";
            return;
        }

        shapes.push_back(newShape);
        cout << newShape->getName() << " ���� �Ϸ�.\n";
    }

    void deleteShape() {
        if (shapes.empty()) {
            cout << "������ ������ �����ϴ�.\n";
            return;
        }

        cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
        int index;
        cin >> index;

        if (index < 0 || index >= shapes.size()) {
            cout << "�߸��� �ε����Դϴ�.\n";
            return;
        }

        delete shapes[index];
        shapes.erase(shapes.begin() + index);
        cout << "���� ���� �Ϸ�.\n";
    }

    void showAllShapes() const {
        if (shapes.empty()) {
            cout << "����� ������ �����ϴ�.\n";
            return;
        }

        for (size_t i = 0; i < shapes.size(); ++i) {
            cout << i << ": " << shapes[i]->getName() << endl;
        }
    }

    void run() {
        while (true) {
            cout << "�׷��� �������Դϴ�.\n";
            cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
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
                cout << "���α׷��� �����մϴ�.\n";
                return;
            default:
                cout << "�߸��� ����Դϴ�.\n";
            }
        }
    }
};

int main() {
    GraphicEditor editor;
    editor.run();
    return 0;
}
