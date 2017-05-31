/*
貍皮ｿ�12-1 List 12-2 縺ｮ邯ｲ謗帙￠驛ｨ蛻�繧呈嶌縺肴鋤縺亥虚菴懊ｒ遒ｺ隱阪○繧�

菴懈�先律 2017蟷ｴ5譛�31譌･

菴懈�占�� 蟷ｳ貔､謨ｬ莉�
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//髢｢謨ｰ螳｣險�
bool file_exist(const char* filename);

int main()
{
	string file_name;		//繝輔ぃ繧､繝ｫ縺ｮ蜷榊燕繧呈枚蟄怜�励→縺励※蜈･蜉帙☆繧句､画焚

	cout << "縺ゅｋ縺九←縺�縺九ｒ遒ｺ隱阪＠縺溘＞繝輔ぃ繧､繝ｫ縺ｮ蜷榊燕 : ";

	cin >> file_name;		//繝輔ぃ繧､繝ｫ縺ｮ蜷榊燕繧呈僑蠑ｵ蟄舌ｒ莉倥￠縺ｦ蜈･蜉�

	//髢｢謨ｰ繧貞他縺ｳ蜃ｺ縺励≠繧九° 辟｡縺�縺�?
	cout << (file_exist(file_name.c_str()) ? ( "ある\n") : ("無い\n"));

	return 0;
}

//髢｢謨ｰ filename縺ｮ蜷榊燕繧呈戟縺､繝輔ぃ繧､繝ｫ縺後≠繧九°縺ｩ縺�縺九�ｮ蛻､蛻･繧定｡後≧
//莉ｮ蠑墓焚 char*蝙九〒繝輔ぃ繧､繝ｫ縺ｮ蜷榊燕
//霑泌唆蛟､ true or false

bool file_exist(const char* filename) {

	ifstream file(filename);		//蜈･蜉帙せ繝医Μ繝ｼ繝�縺ｨ縺励※繧ｪ繝ｼ繝励Φ

	return file.is_open();			//繧ｪ繝ｼ繝励Φ縺ｧ縺阪◆縺九←縺�縺具ｼ�

	//return file;
	//return !file.fail();
}
