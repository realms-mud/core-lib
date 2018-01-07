//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

string EndBar = "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m";
string SkillsRow = "[0;31m| [0m[0;36m%24s[0m : [0;33m%3d[0m [0;34;1m%5s[0m [0;31m| [0m[0;36m%24s[0m : [0;33m%3d[0m [0;34;1m%5s[0m[0;31m |\n[0m";
string HalfRow = "[0;31m| [0m[0;36m%24s[0m : [0;33m%3d[0m [0;34;1m%5s[0m [0;31m|[0m%38s[0;31m|\n[0m";
string SkillPoints = "[0;30;1mYou have %d skill points available to spend.\n[0m";

/////////////////////////////////////////////////////////////////////////////
void PrepSkillsOfType(string type)
{
    object dictionary = load_object("/lib/dictionaries/skillsDictionary.c");
    string *skills = dictionary->validSkillsOfType(type);

    int i = 0;
    foreach(string skill in skills)
    {
        Player->advanceSkill(skill, (i % 10));
        i++;
    }
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "PrepSkillsOfType" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteSkillsCommand()
{
    ExpectTrue(Player->executeCommand("skills"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player->executeCommand("skillsblah"));
    ExpectFalse(Player->executeCommand("askillsd"));
    ExpectFalse(Player->executeCommand("blahskills"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpFailsIfInvalidFlagsPassed()
{
    ExpectFalse(Player->executeCommand("skills -t"));
    ExpectFalse(Player->executeCommand("skills -com"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpFailsIfByFlagPassedWithoutAdvance()
{
    ExpectFalse(Player->executeCommand("skills -by 2"));
}

/////////////////////////////////////////////////////////////////////////////
void CombatFlagOnlyDisplaysCombatSkills()
{
    Player->addSkillPoints(230);
    PrepSkillsOfType("combat");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Combat Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Axe", 0, "", "Blind fighting", 1, "") +
        sprintf(SkillsRow, "Bow", 2, "", "Chainmail", 3, "") +
        sprintf(SkillsRow, "Crossbow", 4, "", "Dagger", 5, "") +
        sprintf(SkillsRow, "Dodge", 6, "", "Dual wield", 7, "") +
        sprintf(SkillsRow, "Flail", 8, "", "Hammer", 9, "") +
        sprintf(SkillsRow, "Hand and a half sword", 0, "", "Hard leather", 1, "") +
        sprintf(SkillsRow, "Long sword", 2, "", "Mace", 3, "") +
        sprintf(SkillsRow, "No armor", 4, "", "Parry", 5, "") +
        sprintf(SkillsRow, "Plate armor", 6, "", "Pole arm", 7, "") +
        sprintf(SkillsRow, "Scalemail", 8, "", "Shield", 9, "") +
        sprintf(SkillsRow, "Short sword", 0, "", "Sling", 1, "") +
        sprintf(SkillsRow, "Soft leather", 2, "", "Splint armor", 3, "") +
        sprintf(SkillsRow, "Staff", 4, "", "Thrown", 5, "") +
        sprintf(SkillsRow, "Two-handed sword", 6, "", "Unarmed", 0, "") + EndBar +
        sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills -combat"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CoFlagOnlyDisplaysCombatSkills()
{
    Player->addSkillPoints(230);
    PrepSkillsOfType("combat");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Combat Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Axe", 0, "", "Blind fighting", 1, "") +
        sprintf(SkillsRow, "Bow", 2, "", "Chainmail", 3, "") +
        sprintf(SkillsRow, "Crossbow", 4, "", "Dagger", 5, "") +
        sprintf(SkillsRow, "Dodge", 6, "", "Dual wield", 7, "") +
        sprintf(SkillsRow, "Flail", 8, "", "Hammer", 9, "") +
        sprintf(SkillsRow, "Hand and a half sword", 0, "", "Hard leather", 1, "") +
        sprintf(SkillsRow, "Long sword", 2, "", "Mace", 3, "") +
        sprintf(SkillsRow, "No armor", 4, "", "Parry", 5, "") +
        sprintf(SkillsRow, "Plate armor", 6, "", "Pole arm", 7, "") +
        sprintf(SkillsRow, "Scalemail", 8, "", "Shield", 9, "") +
        sprintf(SkillsRow, "Short sword", 0, "", "Sling", 1, "") +
        sprintf(SkillsRow, "Soft leather", 2, "", "Splint armor", 3, "") +
        sprintf(SkillsRow, "Staff", 4, "", "Thrown", 5, "") +
        sprintf(SkillsRow, "Two-handed sword", 6, "", "Unarmed", 0, "") + EndBar +
        sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills -co"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CraftingFlagOnlyDisplaysCraftingSkills()
{
    Player->addSkillPoints(225);
    PrepSkillsOfType("crafting");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Crafting Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Acrobatics", 0, "", "Aerophone crafting", 1, "") +
        sprintf(SkillsRow, "Armorer", 2, "", "Blacksmithing", 3, "") +
        sprintf(SkillsRow, "Bowyer and fletcher", 4, "", "Brewing", 5, "") +
        sprintf(SkillsRow, "Carpentry", 6, "", "Dancing", 7, "") +
        sprintf(SkillsRow, "Drum crafting", 8, "", "Gem crafting", 9, "") +
        sprintf(SkillsRow, "Instrument: bowed", 0, "", "Instrument: brass", 1, "") +
        sprintf(SkillsRow, "Instrument: percussion", 2, "", "Instrument: plucked", 3, "") +
        sprintf(SkillsRow, "Instrument: woodwind", 4, "", "Leatherworking", 5, "") +
        sprintf(SkillsRow, "Luthiery", 6, "", "Metal crafting", 7, "") +
        sprintf(SkillsRow, "Mining", 8, "", "Pottery", 9, "") +
        sprintf(SkillsRow, "Sculpture", 0, "", "Sewing", 1, "") +
        sprintf(SkillsRow, "Singing", 2, "", "Stonemasonry", 3, "") +
        sprintf(SkillsRow, "Weapon smithing", 4, "", "Weaving and beadwork", 5, "") +
        sprintf(HalfRow, "Wood crafting", 6, "", "") +
        EndBar + sprintf(SkillPoints, 3);

    ExpectTrue(Player->executeCommand("skills -crafting"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CrFlagOnlyDisplaysCraftingSkills()
{
    Player->addSkillPoints(225);
    PrepSkillsOfType("crafting");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Crafting Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Acrobatics", 0, "", "Aerophone crafting", 1, "") +
        sprintf(SkillsRow, "Armorer", 2, "", "Blacksmithing", 3, "") +
        sprintf(SkillsRow, "Bowyer and fletcher", 4, "", "Brewing", 5, "") +
        sprintf(SkillsRow, "Carpentry", 6, "", "Dancing", 7, "") +
        sprintf(SkillsRow, "Drum crafting", 8, "", "Gem crafting", 9, "") +
        sprintf(SkillsRow, "Instrument: bowed", 0, "", "Instrument: brass", 1, "") +
        sprintf(SkillsRow, "Instrument: percussion", 2, "", "Instrument: plucked", 3, "") +
        sprintf(SkillsRow, "Instrument: woodwind", 4, "", "Leatherworking", 5, "") +
        sprintf(SkillsRow, "Luthiery", 6, "", "Metal crafting", 7, "") +
        sprintf(SkillsRow, "Mining", 8, "", "Pottery", 9, "") +
        sprintf(SkillsRow, "Sculpture", 0, "", "Sewing", 1, "") +
        sprintf(SkillsRow, "Singing", 2, "", "Stonemasonry", 3, "") +
        sprintf(SkillsRow, "Weapon smithing", 4, "", "Weaving and beadwork", 5, "") +
        sprintf(HalfRow, "Wood crafting", 6, "", "") +
        EndBar + sprintf(SkillPoints, 3);

    ExpectTrue(Player->executeCommand("skills -cr"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EruditeFlagOnlyDisplaysEruditeSkills()
{
    Player->addSkillPoints(175);
    PrepSkillsOfType("erudite");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Erudite Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Anatomy and physiology", 0, "", "Ancient history", 1, "") +
        sprintf(SkillsRow, "Astronomy", 2, "", "Chemistry", 3, "") +
        sprintf(SkillsRow, "Engineering", 4, "", "Geology", 5, "") +
        sprintf(SkillsRow, "Herbalism", 6, "", "Linguistics", 7, "") +
        sprintf(SkillsRow, "Local history", 8, "", "Mathematics", 9, "") +
        sprintf(SkillsRow, "Navigation", 0, "", "Perception", 1, "") +
        sprintf(SkillsRow, "Philosophy", 2, "", "Physics", 3, "") +
        sprintf(SkillsRow, "Reading", 4, "", "Spellcraft", 5, "") +
        sprintf(SkillsRow, "Theology", 6, "", "Writing", 7, "") +
        sprintf(HalfRow, "Zoology", 8, "", "") +
        EndBar + sprintf(SkillPoints, 13);

    ExpectTrue(Player->executeCommand("skills -erudite"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EFlagOnlyDisplaysEruditeSkills()
{
    Player->addSkillPoints(175);
    PrepSkillsOfType("erudite");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Erudite Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Anatomy and physiology", 0, "", "Ancient history", 1, "") +
        sprintf(SkillsRow, "Astronomy", 2, "", "Chemistry", 3, "") +
        sprintf(SkillsRow, "Engineering", 4, "", "Geology", 5, "") +
        sprintf(SkillsRow, "Herbalism", 6, "", "Linguistics", 7, "") +
        sprintf(SkillsRow, "Local history", 8, "", "Mathematics", 9, "") +
        sprintf(SkillsRow, "Navigation", 0, "", "Perception", 1, "") +
        sprintf(SkillsRow, "Philosophy", 2, "", "Physics", 3, "") +
        sprintf(SkillsRow, "Reading", 4, "", "Spellcraft", 5, "") +
        sprintf(SkillsRow, "Theology", 6, "", "Writing", 7, "") +
        sprintf(HalfRow, "Zoology", 8, "", "") +
        EndBar + sprintf(SkillPoints, 13);

    ExpectTrue(Player->executeCommand("skills -e"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SubterfugeFlagOnlyDisplaysSubterfugeSkills()
{
    Player->addSkillPoints(105);
    PrepSkillsOfType("subterfuge");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Subterfuge Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Bluff", 0, "", "Climb", 1, "") +
        sprintf(SkillsRow, "Direction sense", 2, "", "Disable traps", 3, "") +
        sprintf(SkillsRow, "Disguise", 4, "", "Find traps", 5, "") +
        sprintf(SkillsRow, "Hide", 6, "", "Listen", 7, "") +
        sprintf(SkillsRow, "Move silently", 8, "", "Open lock", 9, "") +
        sprintf(SkillsRow, "Search", 0, "", "Set traps and snares", 1, "") +
        sprintf(SkillsRow, "Spot", 2, "", "Tracking", 3, "") +
        EndBar + sprintf(SkillPoints, 3);

    ExpectTrue(Player->executeCommand("skills -subterfuge"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SFlagOnlyDisplaysSubterfugeSkills()
{
    Player->addSkillPoints(105);
    PrepSkillsOfType("subterfuge");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Subterfuge Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Bluff", 0, "", "Climb", 1, "") +
        sprintf(SkillsRow, "Direction sense", 2, "", "Disable traps", 3, "") +
        sprintf(SkillsRow, "Disguise", 4, "", "Find traps", 5, "") +
        sprintf(SkillsRow, "Hide", 6, "", "Listen", 7, "") +
        sprintf(SkillsRow, "Move silently", 8, "", "Open lock", 9, "") +
        sprintf(SkillsRow, "Search", 0, "", "Set traps and snares", 1, "") +
        sprintf(SkillsRow, "Spot", 2, "", "Tracking", 3, "") +
        EndBar + sprintf(SkillPoints, 3);

    ExpectTrue(Player->executeCommand("skills -s"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeneralFlagOnlyDisplaysGeneralSkills()
{
    Player->addSkillPoints(102);
    PrepSkillsOfType("general");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Agriculture", 0, "", "Animal handling", 1, "") +
        sprintf(SkillsRow, "Barter", 2, "", "Camp skills", 3, "") +
        sprintf(SkillsRow, "Cooking", 4, "", "Diplomacy", 5, "") +
        sprintf(SkillsRow, "Etiquette", 6, "", "Hunting", 7, "") +
        sprintf(SkillsRow, "Intimidation", 8, "", "Nautical skills", 9, "") +
        sprintf(SkillsRow, "Persuasion", 0, "", "Rope skills", 1, "") +
        sprintf(SkillsRow, "Swimming", 2, "", "Weather sense", 3, "") +
        EndBar + sprintf(SkillPoints, 0);

    ExpectTrue(Player->executeCommand("skills -general"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GFlagOnlyDisplaysGeneralSkills()
{
    Player->addSkillPoints(102);
    PrepSkillsOfType("general");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Agriculture", 0, "", "Animal handling", 1, "") +
        sprintf(SkillsRow, "Barter", 2, "", "Camp skills", 3, "") +
        sprintf(SkillsRow, "Cooking", 4, "", "Diplomacy", 5, "") +
        sprintf(SkillsRow, "Etiquette", 6, "", "Hunting", 7, "") +
        sprintf(SkillsRow, "Intimidation", 8, "", "Nautical skills", 9, "") +
        sprintf(SkillsRow, "Persuasion", 0, "", "Rope skills", 1, "") +
        sprintf(SkillsRow, "Swimming", 2, "", "Weather sense", 3, "") +
        EndBar + sprintf(SkillPoints, 0);

    ExpectTrue(Player->executeCommand("skills -g"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MagicFlagOnlyDisplaysMagicSkills()
{
    Player->addSkillPoints(140);
    PrepSkillsOfType("magic");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Magic Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Animal", 0, "", "Blood", 1, "") +
        sprintf(SkillsRow, "Body", 2, "", "Destruction", 3, "") +
        sprintf(SkillsRow, "Divination", 4, "", "Elemental air", 5, "") +
        sprintf(SkillsRow, "Elemental earth", 6, "", "Elemental fire", 7, "") +
        sprintf(SkillsRow, "Elemental water", 8, "", "Evocation", 9, "") +
        sprintf(SkillsRow, "Magical essence", 0, "", "Manipulation", 1, "") +
        sprintf(SkillsRow, "Mind", 2, "", "Plant", 3, "") +
        sprintf(SkillsRow, "Senses", 4, "", "Spirit", 5, "") +
        sprintf(HalfRow, "Transformation", 6, "", "") +
        EndBar + sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills -magic"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MFlagOnlyDisplaysMagicSkills()
{
    Player->addSkillPoints(140);
    PrepSkillsOfType("magic");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Magic Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Animal", 0, "", "Blood", 1, "") +
        sprintf(SkillsRow, "Body", 2, "", "Destruction", 3, "") +
        sprintf(SkillsRow, "Divination", 4, "", "Elemental air", 5, "") +
        sprintf(SkillsRow, "Elemental earth", 6, "", "Elemental fire", 7, "") +
        sprintf(SkillsRow, "Elemental water", 8, "", "Evocation", 9, "") +
        sprintf(SkillsRow, "Magical essence", 0, "", "Manipulation", 1, "") +
        sprintf(SkillsRow, "Mind", 2, "", "Plant", 3, "") +
        sprintf(SkillsRow, "Senses", 4, "", "Spirit", 5, "") +
        sprintf(HalfRow, "Transformation", 6, "", "") +
        EndBar + sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills -m"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LanguageFlagOnlyDisplaysLanguageSkills()
{
    Player->addSkillPoints(100);
    PrepSkillsOfType("language");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Language Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Andurathi", 0, "", "Common", 1, "") +
        sprintf(SkillsRow, "Draconid", 2, "", "Dwarven", 3, "") +
        sprintf(SkillsRow, "Eledhelean", 4, "", "Elven", 5, "") +
        sprintf(SkillsRow, "Endurghul", 6, "", "High elven", 7, "") +
        sprintf(SkillsRow, "Hillgarathi", 8, "", "Menadrosti", 9, "") +
        sprintf(SkillsRow, "Orcish", 0, "", "Sylvan", 1, "") +
        sprintf(HalfRow, "Tirnosti", 2, "", "") +
        EndBar + sprintf(SkillPoints, 4);

    ExpectTrue(Player->executeCommand("skills -language"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LFlagOnlyDisplaysLanguageSkills()
{
    Player->addSkillPoints(100);
    PrepSkillsOfType("language");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Language Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Andurathi", 0, "", "Common", 1, "") +
        sprintf(SkillsRow, "Draconid", 2, "", "Dwarven", 3, "") +
        sprintf(SkillsRow, "Eledhelean", 4, "", "Elven", 5, "") +
        sprintf(SkillsRow, "Endurghul", 6, "", "High elven", 7, "") +
        sprintf(SkillsRow, "Hillgarathi", 8, "", "Menadrosti", 9, "") +
        sprintf(SkillsRow, "Orcish", 0, "", "Sylvan", 1, "") +
        sprintf(HalfRow, "Tirnosti", 2, "", "") +
        EndBar + sprintf(SkillPoints, 4);

    ExpectTrue(Player->executeCommand("skills -l"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AllFlagDisplaysAllSkills()
{
    Player->addSkillPoints(1060);
    PrepSkillsOfType("combat");
    PrepSkillsOfType("crafting");
    PrepSkillsOfType("erudite");
    PrepSkillsOfType("subterfuge");
    PrepSkillsOfType("general");
    PrepSkillsOfType("magic");
    PrepSkillsOfType("language");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Combat Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Axe", 0, "", "Blind fighting", 1, "") +
        sprintf(SkillsRow, "Bow", 2, "", "Chainmail", 3, "") +
        sprintf(SkillsRow, "Crossbow", 4, "", "Dagger", 5, "") +
        sprintf(SkillsRow, "Dodge", 6, "", "Dual wield", 7, "") +
        sprintf(SkillsRow, "Flail", 8, "", "Hammer", 9, "") +
        sprintf(SkillsRow, "Hand and a half sword", 0, "", "Hard leather", 1, "") +
        sprintf(SkillsRow, "Long sword", 2, "", "Mace", 3, "") +
        sprintf(SkillsRow, "No armor", 4, "", "Parry", 5, "") +
        sprintf(SkillsRow, "Plate armor", 6, "", "Pole arm", 7, "") +
        sprintf(SkillsRow, "Scalemail", 8, "", "Shield", 9, "") +
        sprintf(SkillsRow, "Short sword", 0, "", "Sling", 1, "") +
        sprintf(SkillsRow, "Soft leather", 2, "", "Splint armor", 3, "") +
        sprintf(SkillsRow, "Staff", 4, "", "Thrown", 5, "") +
        sprintf(SkillsRow, "Two-handed sword", 6, "", "Unarmed", 7, "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Crafting Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Acrobatics", 0, "", "Aerophone crafting", 1, "") +
        sprintf(SkillsRow, "Armorer", 2, "", "Blacksmithing", 3, "") +
        sprintf(SkillsRow, "Bowyer and fletcher", 4, "", "Brewing", 5, "") +
        sprintf(SkillsRow, "Carpentry", 6, "", "Dancing", 7, "") +
        sprintf(SkillsRow, "Drum crafting", 8, "", "Gem crafting", 9, "") +
        sprintf(SkillsRow, "Instrument: bowed", 0, "", "Instrument: brass", 1, "") +
        sprintf(SkillsRow, "Instrument: percussion", 2, "", "Instrument: plucked", 3, "") +
        sprintf(SkillsRow, "Instrument: woodwind", 4, "", "Leatherworking", 5, "") +
        sprintf(SkillsRow, "Luthiery", 6, "", "Metal crafting", 7, "") +
        sprintf(SkillsRow, "Mining", 8, "", "Pottery", 9, "") +
        sprintf(SkillsRow, "Sculpture", 0, "", "Sewing", 1, "") +
        sprintf(SkillsRow, "Singing", 2, "", "Stonemasonry", 3, "") +
        sprintf(SkillsRow, "Weapon smithing", 4, "", "Weaving and beadwork", 5, "") +
        sprintf(HalfRow, "Wood crafting", 6, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Erudite Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Anatomy and physiology", 0, "", "Ancient history", 1, "") +
        sprintf(SkillsRow, "Astronomy", 2, "", "Chemistry", 3, "") +
        sprintf(SkillsRow, "Engineering", 4, "", "Geology", 5, "") +
        sprintf(SkillsRow, "Herbalism", 6, "", "Linguistics", 7, "") +
        sprintf(SkillsRow, "Local history", 8, "", "Mathematics", 9, "") +
        sprintf(SkillsRow, "Navigation", 0, "", "Perception", 1, "") +
        sprintf(SkillsRow, "Philosophy", 2, "", "Physics", 3, "") +
        sprintf(SkillsRow, "Reading", 4, "", "Spellcraft", 5, "") +
        sprintf(SkillsRow, "Theology", 6, "", "Writing", 7, "") +
        sprintf(HalfRow, "Zoology", 8, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Agriculture", 0, "", "Animal handling", 1, "") +
        sprintf(SkillsRow, "Barter", 2, "", "Camp skills", 3, "") +
        sprintf(SkillsRow, "Cooking", 4, "", "Diplomacy", 5, "") +
        sprintf(SkillsRow, "Etiquette", 6, "", "Hunting", 7, "") +
        sprintf(SkillsRow, "Intimidation", 8, "", "Nautical skills", 9, "") +
        sprintf(SkillsRow, "Persuasion", 0, "", "Rope skills", 1, "") +
        sprintf(SkillsRow, "Swimming", 2, "", "Weather sense", 3, "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Language Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Andurathi", 0, "", "Common", 1, "") +
        sprintf(SkillsRow, "Draconid", 2, "", "Dwarven", 3, "") +
        sprintf(SkillsRow, "Eledhelean", 4, "", "Elven", 5, "") +
        sprintf(SkillsRow, "Endurghul", 6, "", "High elven", 7, "") +
        sprintf(SkillsRow, "Hillgarathi", 8, "", "Menadrosti", 9, "") +
        sprintf(SkillsRow, "Orcish", 0, "", "Sylvan", 1, "") +
        sprintf(HalfRow, "Tirnosti", 2, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Magic Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Animal", 0, "", "Blood", 1, "") +
        sprintf(SkillsRow, "Body", 2, "", "Destruction", 3, "") +
        sprintf(SkillsRow, "Divination", 4, "", "Elemental air", 5, "") +
        sprintf(SkillsRow, "Elemental earth", 6, "", "Elemental fire", 7, "") +
        sprintf(SkillsRow, "Elemental water", 8, "", "Evocation", 9, "") +
        sprintf(SkillsRow, "Magical essence", 0, "", "Manipulation", 1, "") +
        sprintf(SkillsRow, "Mind", 2, "", "Plant", 3, "") +
        sprintf(SkillsRow, "Senses", 4, "", "Spirit", 5, "") +
        sprintf(HalfRow, "Transformation", 6, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Subterfuge Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Bluff", 0, "", "Climb", 1, "") +
        sprintf(SkillsRow, "Direction sense", 2, "", "Disable traps", 3, "") +
        sprintf(SkillsRow, "Disguise", 4, "", "Find traps", 5, "") +
        sprintf(SkillsRow, "Hide", 6, "", "Listen", 7, "") +
        sprintf(SkillsRow, "Move silently", 8, "", "Open lock", 9, "") +
        sprintf(SkillsRow, "Search", 0, "", "Set traps and snares", 1, "") +
        sprintf(SkillsRow, "Spot", 2, "", "Tracking", 3, "") +
        EndBar + sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills -all"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoFlagDisplaysAllSkills()
{
    Player->addSkillPoints(1060);
    PrepSkillsOfType("combat");
    PrepSkillsOfType("crafting");
    PrepSkillsOfType("erudite");
    PrepSkillsOfType("subterfuge");
    PrepSkillsOfType("general");
    PrepSkillsOfType("magic");
    PrepSkillsOfType("language");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Combat Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Axe", 0, "", "Blind fighting", 1, "") +
        sprintf(SkillsRow, "Bow", 2, "", "Chainmail", 3, "") +
        sprintf(SkillsRow, "Crossbow", 4, "", "Dagger", 5, "") +
        sprintf(SkillsRow, "Dodge", 6, "", "Dual wield", 7, "") +
        sprintf(SkillsRow, "Flail", 8, "", "Hammer", 9, "") +
        sprintf(SkillsRow, "Hand and a half sword", 0, "", "Hard leather", 1, "") +
        sprintf(SkillsRow, "Long sword", 2, "", "Mace", 3, "") +
        sprintf(SkillsRow, "No armor", 4, "", "Parry", 5, "") +
        sprintf(SkillsRow, "Plate armor", 6, "", "Pole arm", 7, "") +
        sprintf(SkillsRow, "Scalemail", 8, "", "Shield", 9, "") +
        sprintf(SkillsRow, "Short sword", 0, "", "Sling", 1, "") +
        sprintf(SkillsRow, "Soft leather", 2, "", "Splint armor", 3, "") +
        sprintf(SkillsRow, "Staff", 4, "", "Thrown", 5, "") +
        sprintf(SkillsRow, "Two-handed sword", 6, "", "Unarmed", 7, "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Crafting Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Acrobatics", 0, "", "Aerophone crafting", 1, "") +
        sprintf(SkillsRow, "Armorer", 2, "", "Blacksmithing", 3, "") +
        sprintf(SkillsRow, "Bowyer and fletcher", 4, "", "Brewing", 5, "") +
        sprintf(SkillsRow, "Carpentry", 6, "", "Dancing", 7, "") +
        sprintf(SkillsRow, "Drum crafting", 8, "", "Gem crafting", 9, "") +
        sprintf(SkillsRow, "Instrument: bowed", 0, "", "Instrument: brass", 1, "") +
        sprintf(SkillsRow, "Instrument: percussion", 2, "", "Instrument: plucked", 3, "") +
        sprintf(SkillsRow, "Instrument: woodwind", 4, "", "Leatherworking", 5, "") +
        sprintf(SkillsRow, "Luthiery", 6, "", "Metal crafting", 7, "") +
        sprintf(SkillsRow, "Mining", 8, "", "Pottery", 9, "") +
        sprintf(SkillsRow, "Sculpture", 0, "", "Sewing", 1, "") +
        sprintf(SkillsRow, "Singing", 2, "", "Stonemasonry", 3, "") +
        sprintf(SkillsRow, "Weapon smithing", 4, "", "Weaving and beadwork", 5, "") +
        sprintf(HalfRow, "Wood crafting", 6, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Erudite Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Anatomy and physiology", 0, "", "Ancient history", 1, "") +
        sprintf(SkillsRow, "Astronomy", 2, "", "Chemistry", 3, "") +
        sprintf(SkillsRow, "Engineering", 4, "", "Geology", 5, "") +
        sprintf(SkillsRow, "Herbalism", 6, "", "Linguistics", 7, "") +
        sprintf(SkillsRow, "Local history", 8, "", "Mathematics", 9, "") +
        sprintf(SkillsRow, "Navigation", 0, "", "Perception", 1, "") +
        sprintf(SkillsRow, "Philosophy", 2, "", "Physics", 3, "") +
        sprintf(SkillsRow, "Reading", 4, "", "Spellcraft", 5, "") +
        sprintf(SkillsRow, "Theology", 6, "", "Writing", 7, "") +
        sprintf(HalfRow, "Zoology", 8, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Agriculture", 0, "", "Animal handling", 1, "") +
        sprintf(SkillsRow, "Barter", 2, "", "Camp skills", 3, "") +
        sprintf(SkillsRow, "Cooking", 4, "", "Diplomacy", 5, "") +
        sprintf(SkillsRow, "Etiquette", 6, "", "Hunting", 7, "") +
        sprintf(SkillsRow, "Intimidation", 8, "", "Nautical skills", 9, "") +
        sprintf(SkillsRow, "Persuasion", 0, "", "Rope skills", 1, "") +
        sprintf(SkillsRow, "Swimming", 2, "", "Weather sense", 3, "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Language Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Andurathi", 0, "", "Common", 1, "") +
        sprintf(SkillsRow, "Draconid", 2, "", "Dwarven", 3, "") +
        sprintf(SkillsRow, "Eledhelean", 4, "", "Elven", 5, "") +
        sprintf(SkillsRow, "Endurghul", 6, "", "High elven", 7, "") +
        sprintf(SkillsRow, "Hillgarathi", 8, "", "Menadrosti", 9, "") +
        sprintf(SkillsRow, "Orcish", 0, "", "Sylvan", 1, "") +
        sprintf(HalfRow, "Tirnosti", 2, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Magic Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Animal", 0, "", "Blood", 1, "") +
        sprintf(SkillsRow, "Body", 2, "", "Destruction", 3, "") +
        sprintf(SkillsRow, "Divination", 4, "", "Elemental air", 5, "") +
        sprintf(SkillsRow, "Elemental earth", 6, "", "Elemental fire", 7, "") +
        sprintf(SkillsRow, "Elemental water", 8, "", "Evocation", 9, "") +
        sprintf(SkillsRow, "Magical essence", 0, "", "Manipulation", 1, "") +
        sprintf(SkillsRow, "Mind", 2, "", "Plant", 3, "") +
        sprintf(SkillsRow, "Senses", 4, "", "Spirit", 5, "") +
        sprintf(HalfRow, "Transformation", 6, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Subterfuge Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Bluff", 0, "", "Climb", 1, "") +
        sprintf(SkillsRow, "Direction sense", 2, "", "Disable traps", 3, "") +
        sprintf(SkillsRow, "Disguise", 4, "", "Find traps", 5, "") +
        sprintf(SkillsRow, "Hide", 6, "", "Listen", 7, "") +
        sprintf(SkillsRow, "Move silently", 8, "", "Open lock", 9, "") +
        sprintf(SkillsRow, "Search", 0, "", "Set traps and snares", 1, "") +
        sprintf(SkillsRow, "Spot", 2, "", "Tracking", 3, "") +
        EndBar + sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MagicalEnhancementsModifySkillValues()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("short", "Sword of Blah");
    weapon->set("weapon type", "long sword");
    weapon->set("bonus long sword", 3);
    weapon->set("bonus bow", 1);
    weapon->set("bonus hammer", 5);
    move_object(weapon, Player);
    weapon->equip("blah");

    Player->addSkillPoints(230);
    PrepSkillsOfType("combat");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Combat Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Axe", 0, "", "Blind fighting", 1, "") +
        sprintf(SkillsRow, "Bow", 2, "(+1)", "Chainmail", 3, "") +
        sprintf(SkillsRow, "Crossbow", 4, "", "Dagger", 5, "") +
        sprintf(SkillsRow, "Dodge", 6, "", "Dual wield", 7, "") +
        sprintf(SkillsRow, "Flail", 8, "", "Hammer", 9, "(+5)") +
        sprintf(SkillsRow, "Hand and a half sword", 0, "", "Hard leather", 1, "") +
        sprintf(SkillsRow, "Long sword", 2, "(+3)", "Mace", 3, "") +
        sprintf(SkillsRow, "No armor", 4, "", "Parry", 5, "") +
        sprintf(SkillsRow, "Plate armor", 6, "", "Pole arm", 7, "") +
        sprintf(SkillsRow, "Scalemail", 8, "", "Shield", 9, "") +
        sprintf(SkillsRow, "Short sword", 0, "", "Sling", 1, "") +
        sprintf(SkillsRow, "Soft leather", 2, "", "Splint armor", 3, "") +
        sprintf(SkillsRow, "Staff", 4, "", "Thrown", 5, "") +
        sprintf(SkillsRow, "Two-handed sword", 6, "", "Unarmed", 0, "") + EndBar +
        sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills -combat"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MagicalEnhancementsDoNotModifySkillsThatAreZero()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("short", "Sword of Blah");
    weapon->set("weapon type", "long sword");
    weapon->set("bonus axe", 3);
    weapon->set("bonus bow", 1);
    move_object(weapon, Player);
    weapon->equip("blah");

    Player->addSkillPoints(230);
    PrepSkillsOfType("combat");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Combat Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Axe", 0, "", "Blind fighting", 1, "") +
        sprintf(SkillsRow, "Bow", 2, "(+1)", "Chainmail", 3, "") +
        sprintf(SkillsRow, "Crossbow", 4, "", "Dagger", 5, "") +
        sprintf(SkillsRow, "Dodge", 6, "", "Dual wield", 7, "") +
        sprintf(SkillsRow, "Flail", 8, "", "Hammer", 9, "") +
        sprintf(SkillsRow, "Hand and a half sword", 0, "", "Hard leather", 1, "") +
        sprintf(SkillsRow, "Long sword", 2, "", "Mace", 3, "") +
        sprintf(SkillsRow, "No armor", 4, "", "Parry", 5, "") +
        sprintf(SkillsRow, "Plate armor", 6, "", "Pole arm", 7, "") +
        sprintf(SkillsRow, "Scalemail", 8, "", "Shield", 9, "") +
        sprintf(SkillsRow, "Short sword", 0, "", "Sling", 1, "") +
        sprintf(SkillsRow, "Soft leather", 2, "", "Splint armor", 3, "") +
        sprintf(SkillsRow, "Staff", 4, "", "Thrown", 5, "") +
        sprintf(SkillsRow, "Two-handed sword", 6, "", "Unarmed", 0, "") + EndBar +
        sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills -combat"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillFailsIfNotAValidSkill()
{
    Player->addSkillPoints(230);
    ExpectFalse(Player->executeCommand("skills -advance weasel"));
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillFailsIfNotEnoughSkillPointsToAdvance()
{
    ExpectFalse(Player->executeCommand("skills -advance long sword"));
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillSucceeds()
{
    Player->addSkillPoints(10);
    ExpectTrue(Player->executeCommand("skills -advance long sword"));
    ExpectEq("You have increased your 'long sword' skill by 1 and it is now 1.\n", Player->caughtMessage());

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Combat Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Axe", 0, "", "Blind fighting", 0, "") +
        sprintf(SkillsRow, "Bow", 0, "", "Chainmail", 0, "") +
        sprintf(SkillsRow, "Crossbow", 0, "", "Dagger", 0, "") +
        sprintf(SkillsRow, "Dodge", 0, "", "Dual wield", 0, "") +
        sprintf(SkillsRow, "Flail", 0, "", "Hammer", 0, "") +
        sprintf(SkillsRow, "Hand and a half sword", 0, "", "Hard leather", 0, "") +
        sprintf(SkillsRow, "Long sword", 1, "", "Mace", 0, "") +
        sprintf(SkillsRow, "No armor", 0, "", "Parry", 0, "") +
        sprintf(SkillsRow, "Plate armor", 0, "", "Pole arm", 0, "") +
        sprintf(SkillsRow, "Scalemail", 0, "", "Shield", 0, "") +
        sprintf(SkillsRow, "Short sword", 0, "", "Sling", 0, "") +
        sprintf(SkillsRow, "Soft leather", 0, "", "Splint armor", 0, "") +
        sprintf(SkillsRow, "Staff", 0, "", "Thrown", 0, "") +
        sprintf(SkillsRow, "Two-handed sword", 0, "", "Unarmed", 0, "") + EndBar +

        sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills -combat"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillByValueSucceeds()
{
    Player->addSkillPoints(10);
    ExpectTrue(Player->executeCommand("skills -advance long sword -by 3"));
    ExpectEq("You have increased your 'long sword' skill by 3 and it is now 3.\n", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillByValueFailsWhenNotEnoughSkillPoints()
{
    Player->addSkillPoints(2);
    ExpectFalse(Player->executeCommand("skills -advance long sword -by 3"));
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillByValueFailsWhenNotAnInteger()
{
    Player->addSkillPoints(2);
    ExpectFalse(Player->executeCommand("skills -advance long sword -by cabbage"));
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillByValueFailsWhenNoValuePassed()
{
    Player->addSkillPoints(2);
    ExpectFalse(Player->executeCommand("skills -advance long sword -by"));
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillFailsWhenRelatedAttributeTooLow()
{
    Player->addSkillPoints(25);
    ExpectTrue(Player->executeCommand("skills -advance long sword -by 10"));
    ExpectEq("You have increased your 'long sword' skill by 10 and it is now 10.\n", Player->caughtMessage());
    ExpectFalse(Player->executeCommand("skills -advance long sword"));
}
