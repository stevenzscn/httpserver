#ifndef _UTILS_H__
#define _UTILS_H__

namespace utils
{

template<class T>
class Singleton: private T
{
public:
	static T &Instance()
	{
		static Singleton<T> instance_;
		return instance_;
	}
private:
	Singleton()
	{
	}
	~Singleton()
	{
	}
};

template<typename T>
T& G()
{
	return Singleton<T>::Instance();
}

}
#endif
