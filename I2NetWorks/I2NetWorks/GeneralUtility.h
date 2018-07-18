#pragma once
class GeneralUtility
{
public:
	GeneralUtility(void);
	~GeneralUtility(void);
	class socketcommunication{
	public :
		socketcommunication();
		~socketcommunication();
		int opensocketConnection();
		int closesocketConnection();
		int GetDataFromConnection();
		int SendDataToConnection();
		int ListenOnPort();

	};
	class Logging{
	public :
		Logging();
		~Logging();

	};
};

