#pragma once

#include <GLFW\glfw3.h>

namespace ZEROGE {
	class Window
	{
	public:
		Window(int width, int height, const char* title);
		~Window();
		bool closed() const;
		void update();
		void clear() const;
		void setColorWindow();

		inline int getWidth() const { return mWidth; }
		inline int getHeight() const { return mHeight; }


	private:
		const char* mTitle;
		int mWidth, mHeight;
		GLFWwindow* mWindow;
		bool mClosed;
		bool Init();

	};
}
