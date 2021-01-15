#include <string>

class Drawable {
public:
    Drawable(int id);
    void draw();
private:
    int m_id;
};

class Rectangle : public virtual Drawable {
public:
    Rectangle(int id, float width, float height);
protected:
    int m_width;
    int m_height;
};

class Text : public virtual Drawable {
public:
    Text(int id, std::string content);
protected:
    std::string m_content;
};

class TextBox : public Rectangle, public Text {
public:
    TextBox(std::string content,
            float width, float height);
};

