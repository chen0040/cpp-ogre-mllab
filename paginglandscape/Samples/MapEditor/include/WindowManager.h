#ifndef GUI_WINDOW_MANAGER_H_
#define GUI_WINDOW_MANAGER_H_

#include <map>
#include <string>

struct ltstr
{
	bool operator()(std::string s1, std::string s2) const
	{
		return s1 < s2;
	}
};

class GUIWindowManager
{
private:
	std::map<std::string, CEGUI::Window*, ltstr> mWindows;
protected:
public:
				GUIWindowManager(void);
				~GUIWindowManager(void);
	void		addWindow(std::string name, CEGUI::Window* window);
	void		removeWindow(std::string name);
};

#endif
