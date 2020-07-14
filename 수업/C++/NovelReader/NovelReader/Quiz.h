#pragma once
class Quiz {
	virtual void pro() = 0;
};

class QuizMean : Quiz {
	void pro();
};
class QuizWord : Quiz {
	void pro();
};
