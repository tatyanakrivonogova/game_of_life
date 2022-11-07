#include "gtest\gtest.h"
#include "gameOfLife.h"

TEST(GameOfLifeTests, testUniverse) {
	Universe u;
	EXPECT_EQ(u.height(), 0);
	EXPECT_EQ(u.width(), 0);
	EXPECT_EQ(u.getName(), "");

	std::string name = "name";
	std::vector<int> born = { 2, 3 };
	std::vector<int> survive = { 2 };
	u = Universe(name, born, survive);
	EXPECT_EQ(u.width(), 1);
	EXPECT_EQ(u.height(), 1);
	EXPECT_EQ(u.getCell(0, 0), false);

	u.setCell(10, 8, true);
	EXPECT_EQ(u.width(), 11);
	EXPECT_EQ(u.height(), 9);
	EXPECT_EQ(u.getCell(10, 8), true);
	bool flag = true;
	for (int i = 0; i < u.width(); ++i) {
		for (int j = 0; j < u.height(); ++j) {
			if (i != 10 and j != 8 and u.getCell(i, j) == true) {
				flag = false;
			}
		}
	}
	EXPECT_TRUE(flag == true);
	name = "name";
	EXPECT_EQ(u.getName(), name);
	EXPECT_EQ(u.getCell(21, 17), true);

	born = { 2, 3 };
	survive = { 2 };
	EXPECT_EQ(u.getBornRule().size(), 2);
	EXPECT_EQ(u.getSurviveRule().size(), 1);
	EXPECT_EQ(u.getBornRule(), born);
	EXPECT_EQ(u.getSurviveRule(), survive);
}

TEST(GameOfLifeTests, testCreateUniverseFile) {
	creatorFactory creatorFactory;

	std::ifstream fin("test_in.txt");
	std::shared_ptr<createUniverse> creator = creatorFactory.buildCreator(file, &fin);
	Universe u = creator->create();

	std::string name = "test_name";
	EXPECT_EQ(u.getName(), name);

	std::vector<int> born = { 5, 2 };
	std::vector<int> survive = { 8, 7 };
	EXPECT_EQ(u.getBornRule(), born);
	EXPECT_EQ(u.getSurviveRule(), survive);

	EXPECT_EQ(u.width(), 4);
	EXPECT_EQ(u.height(), 6);

	EXPECT_EQ(u.getCell(0, 0), false);
	EXPECT_EQ(u.getCell(0, 1), true);
	EXPECT_EQ(u.getCell(0, 2), true);
	EXPECT_EQ(u.getCell(1, 0), true);
	EXPECT_EQ(u.getCell(1, 1), false);
	EXPECT_EQ(u.getCell(1, 2), false);

}

TEST(GameOfLifeTests, testShowUniverseFile) {
	creatorFactory creatorFactory;
	showerFactory showerFactory;

	std::ifstream fin("test_in.txt");
	std::shared_ptr<createUniverse> creator = creatorFactory.buildCreator(file, &fin);
	Universe u = creator->create();

	std::ofstream fout("test_out.life");
	std::shared_ptr<showUniverse> shower = showerFactory.buildShower(outputfile, &u, &fout);
	shower->show();

	std::ifstream fin1("test_out.life");
	createUniverse* creator1 = new createUniverseFile(&fin1);
	Universe u1 = creator1->create();

	EXPECT_EQ(u.getName(), u1.getName());
	EXPECT_EQ(u.width(), u1.width());
	EXPECT_EQ(u.height(), u1.height());
	EXPECT_EQ(u.getBornRule(), u1.getBornRule());
	EXPECT_EQ(u.getSurviveRule(), u1.getSurviveRule());

	bool flag = true;
	for (int i = 0; i < u.width(); ++i) {
		for (int j = 0; j < u.height(); ++j) {
			if (u.getCell(i, j) != u1.getCell(i, j)) {
				flag = false;
			}
		}
	}
	EXPECT_TRUE(flag == true);
}

TEST(GameOfLifeTests, testRunLife) {
	creatorFactory creatorFactory;
	runnerFactory runnerFactory;

	std::ifstream fin("test_in.txt");
	std::shared_ptr<createUniverse> creator = creatorFactory.buildCreator(file, &fin);
	Universe u = creator->create();
	std::shared_ptr<runLife> runner = runnerFactory.buildRunner(cmd, &u);
	runner->changeUniverse();


	std::ifstream fin1("test_in_after.txt");
	std::shared_ptr<createUniverse> creator1 = creatorFactory.buildCreator(file, &fin1);
	Universe u1 = creator1->create();
	
	EXPECT_TRUE(u.is_similar(u1));

}