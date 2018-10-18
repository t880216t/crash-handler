#include <thread>
#include <mutex>

class Process {
public:
	Process(uint64_t pid, bool isCritical);
	~Process();

private:
	uint64_t m_pid;
	bool m_isCritical;
	std::thread* m_worker;
	bool m_isAlive;
	bool m_stop;
	std::string m_name;

public:
	std::mutex mutex;

	uint64_t getPID(void);
	void setPID(uint64_t pid);
	bool getCritical(void);
	void setCritical(bool isCritical);
	bool getAlive(void);
	void setAlive(bool isAlive);
	bool getStopped(void);
	std::thread* getWorker(void);

	void stopWorker();
};