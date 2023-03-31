#include<bits/stdc++.h>
using namespace std;

map <char, pair<int, int>> Move{ {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}} };

struct S
{
	int y, x;
	int hp = 20, ad = 2, am = 2;
	int lv = 1, ex, we, df;
	string die, ac[4];

	int hp_f() { return 20 + (lv - 1) * 5; }
	void lev_up()
	{
		lv++;
		hp = hp_f();
		ad += 2, am += 2;
		ex = 0;
	}
}Me;
struct E
{
	string name;
	int y, x;
	int hp, ad, am, ex;
}Eny[10001];
struct I
{
	char type;
	string P;
	int y, x;
	int ad, am;
}Item[10001];

int py, px, IMap[101][101];
char Map[101][101];
string com;
int fy, fx, n, m, u, bn;



void in()
{
	int k{}, l{};
	cin >> n >> m;
	for (int i(1); i <= n; i++)
		for (int j(1); j <= m; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == '@') fy = Me.y = i, fx = Me.x = j;
			k += Map[i][j] == '&' || Map[i][j] == 'M';
			l += Map[i][j] == 'B';
		}
	cin >> com;
	for (int i{}; i < k; i++)
	{
		cin >> Eny[i].y >> Eny[i].x >> Eny[i].name >> Eny[i].ad >> Eny[i].am >> Eny[i].hp >> Eny[i].ex;
		if (Map[Eny[i].y][Eny[i].x] == 'M') bn = i;
		IMap[Eny[i].y][Eny[i].x] = i;
	}
	for (int i{}; i < l; i++)
	{
		cin >> Item[i].y >> Item[i].x >> Item[i].type >> Item[i].P;
		IMap[Item[i].y][Item[i].x] = i;
	}
}



int ac_range(string s, int r = 0)
{
	for (int i{}; i < 4; i++)
		if (Me.ac[i] == s)
			r += 1;
	return r;
}



void end_f(int code)
{
	string res;
	if (!code) res = "YOU WIN!";
	else if (code == 3) res = "Press any key to continue.";
	else res = "YOU HAVE BEEN KILLED BY " + Me.die + "..";

	if (code ^ 1 && code ^ 2 && Map[Me.y][Me.x] ^ '@') Map[Me.y][Me.x] = '@';
	for (int i(1); i <= n; puts(""), i++)
		for (int j(1); j <= m; cout << Map[i][j++]);
	auto f(printf);
	f("Passed Turns : %d\n", u);
	f("LV : %d\n", Me.lv);
	f("HP : %d/%d\n", max(0, Me.hp), Me.hp_f());
	f("ATT : %d+%d\n", Me.ad, Me.we);
	f("DEF : %d+%d\n", Me.am, Me.df);
	f("EXP : %d/%d\n", Me.ex, Me.lv * 5);
	cout << res;
	exit(0);
}



void we_f(I t)
{
	Me.we = stoi(t.P);
}
void df_f(I t)
{
	Me.df = stoi(t.P);
}
void ac_f(I t)
{
	for (int i{}; i < 4; i++)
		if (Me.ac[i] == t.P)
			return;
	for (int i{}; i < 4; i++)
		if (!Me.ac[i].size())
			Me.ac[i] = t.P, i = 4;
}
int re_f()
{
	for (int i{}; i < 4; i++)
		if (Me.ac[i] == "RE")
		{
			Me.ac[i].clear();
			Me.hp = Me.hp_f();
			Me.y = fy, Me.x = fx;
			Map[fy][fx] = '@';
			return 1;
		}
	return 0;
}
void item_f()
{
	auto& t(Item[IMap[Me.y][Me.x]]);
	if (Map[py][px] ^ '^') Map[py][px] = '.';
	Map[Me.y][Me.x] = '@';
	t.type == 'W' ? we_f(t) : (t.type == 'A' ? df_f(t) : ac_f(t));
}



void trap_f()
{
	if (Map[py][px] ^ '^') Map[py][px] = '.';
	Me.hp -= ac_range("DX") ? 1 : 5;
	if (Me.hp < 1)
	{
		if (re_f()) return;
		Me.die = "SPIKE TRAP", end_f(2);
	}
}



void normap_f()
{
	if (Map[py][px] ^ '^') Map[py][px] = '.';
	Map[Me.y][Me.x] = '@';
}



void boss_f(E& t, int shield = 0)
{
	if (ac_range("HU")) Me.hp = Me.hp_f(), shield = 1;
	int attak_damage = Me.ad + Me.we, t_hp(t.hp), dam_x{};

	if (ac_range("CO")) dam_x = 1;
	while (1)
	{

		if (dam_x) dam_x = 0, t.hp -= max(1, attak_damage * (ac_range("DX") ? 3 : 2) - t.am);
		else t.hp -= max(1, attak_damage - t.am);

		if (t.hp < 1)
		{
			if (Map[py][px] ^ '^') Map[py][px] = '.';
			Map[t.y][t.x] = '@';
			Me.ex += ac_range("EX") ? t.ex * 1.2 : t.ex;
			if (ac_range("HR")) Me.hp = min(Me.hp_f(), Me.hp + 3);
			if (Me.ex >= Me.lv * 5) Me.lev_up();
			end_f(0);
		}
		if (shield) shield = 0;
		else Me.hp -= max(1, t.ad - (Me.am + Me.df));
		if (Me.hp < 1)
		{
			if (re_f())
			{
				t.hp = t_hp;
				return;
			}
			Me.die = t.name;
			end_f(1);
		}
	}
}
void enemy_f()
{
	E& t(Eny[IMap[Me.y][Me.x]]);
	int attak_damage = Me.ad + Me.we, t_hp(t.hp), dam_x{};
	if (Map[py][px] ^ '^') Map[py][px] = '.';
	if (IMap[Me.y][Me.x] == bn)
	{
		boss_f(t);
		return;
	}

	if (ac_range("CO")) dam_x = 1;
	while (1)
	{
		if (dam_x) dam_x = 0, t.hp -= max(1, attak_damage * (ac_range("DX") ? 3 : 2) - t.am);
		else t.hp -= max(1, attak_damage - t.am);
		if (t.hp < 1)
		{
			Map[t.y][t.x] = '@';
			Me.ex += ac_range("EX") ? t.ex * 1.2 : t.ex;
			if (ac_range("HR")) Me.hp = min(Me.hp_f(), Me.hp + 3);
			if (Me.ex >= Me.lv * 5) Me.lev_up();
			return;
		}
		Me.hp -= max(1, t.ad - (Me.am + Me.df));
		if (Me.hp < 1)
		{
			if (re_f())
			{
				t.hp = t_hp;
				return;
			}
			Me.die = t.name;
			end_f(1);
		}
	}
}




void sv()
{
	for (; u < (int)com.size();)
	{
		int y(Me.y + Move[com[u]].first), x(Me.x + Move[com[u]].second);
		char o{}; u++;
		if (py = Me.y, px = Me.x; y && x && y <= n && x <= m && Map[y][x] ^ '#')
			Me.y = y, Me.x = x, o = Map[Me.y][Me.x];
		if (!o && Map[Me.y][Me.x] == '^') trap_f();
		else if (o)
			if (o == 'B') item_f();
			else if (o == '^') trap_f();
			else if (o == '.') normap_f();
			else enemy_f();
	}
	end_f(3);
}



int main()
{
	in();
	sv();
}
