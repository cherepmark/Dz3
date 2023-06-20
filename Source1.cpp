#include <iostream>
#include <vector>
#include <algorithm>


class Spell
{
public:
	int power;
	int mana;

	Spell(int power, int mana) : power(power), mana(mana) {}
};

bool operator<(const Spell& lhs, const Spell& rhs) {
	return lhs.mana < rhs.mana;
}

struct SpellComp {
	bool operator()(const Spell& lhs, const Spell& rhs) {
		if (lhs.power == rhs.power) {
			return lhs.mana > rhs.mana;
		}
		return lhs.power < rhs.power;
	}
};

int main()
{
	std::vector<Spell> spells;
	spells.emplace_back(Spell(12, 3));
	spells.emplace_back(Spell(4, 11));
	spells.emplace_back(Spell(6, 7));
	spells.emplace_back(Spell(6, 2));

	sort(spells.begin(), spells.end());
	std::cout << "Sorted by mana:" << std::endl;
	for (const auto& spell : spells) {
		std::cout << "Power: " << spell.power << ", Mana: " << spell.mana << std::endl;
	}

	sort(spells.begin(), spells.end(), SpellComp());
	std::cout << "Sorted by power:" << std::endl;
	for (const auto& spell : spells)
	{
		std::cout << "Power: " << spell.power << ", Mana: " << spell.mana << std::endl;
	}

	return 0;
}
