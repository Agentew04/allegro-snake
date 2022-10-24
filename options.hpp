#ifndef OPTIONS_HPP
#define OPTIONS_HPP

struct VideoOptions{
private:
    static const int kDefaultWidth = 640;
    static const int kDefaultHeight = 480;

    int width;
    int height;

    bool fullscreen;

public:
    VideoOptions();

    bool isFullscreen() const;
    void setFullscreen(bool fullscreen);

    int getWidth() const;
    void setWidth(int width);

    int getHeight() const;
    void setHeight(int height);
};

#endif // OPTIONS_HPP