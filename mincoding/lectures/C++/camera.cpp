#include <iostream>

class ICamera
{
public:
    virtual ~ICamera() {}
    virtual void take() = 0;
};

class Photograpper
{
public:
    void useCamera(ICamera *camera)
    { // 특정 객체를 적지 말자
        // Camera, HDCamera
        // 포인터는 만들수 있다.
        camera->take();
    }
};

class Camera : public ICamera
{
public:
    void take()
    {
        std::cout << "사진을 찍다." << std::endl;
    }
};

class HDCamera : public ICamera
{
public:
    void take()
    {
        std::cout << "고화질 사진을 찍다." << std::endl;
    }
};

class UHDCamera : public ICamera
{
public:
    void take()
    {
        std::cout << "초고화질 사진을 찍다." << std::endl;
    }
};

int main()
{
    Photograpper p;
    Camera c;
    p.useCamera(&c);

    HDCamera hc;
    p.useCamera(&hc);

    UHDCamera uhc;
    p.useCamera(&uhc);

    return (0);
}