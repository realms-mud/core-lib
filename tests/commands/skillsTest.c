//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        sprintf(SkillsRow, "Axe", 0, "", "Bow", 1, "") +
        sprintf(SkillsRow, "Chainmail", 2, "", "Crossbow", 3, "") +
        sprintf(SkillsRow, "Dagger", 4, "", "Dodge", 5, "") +
        sprintf(SkillsRow, "Dual wield", 6, "", "Flail", 7, "") +
        sprintf(SkillsRow, "Hammer", 8, "", "Hand and a half sword", 9, "") +
        sprintf(SkillsRow, "Hard leather", 0, "", "Long sword", 1, "") +
        sprintf(SkillsRow, "Mace", 2, "", "No armor", 3, "") +
        sprintf(SkillsRow, "Parry", 4, "", "Plate armor", 5, "") +
        sprintf(SkillsRow, "Pole arm", 6, "", "Scalemail", 7, "") +
        sprintf(SkillsRow, "Shield", 8, "", "Short sword", 9, "") +
        sprintf(SkillsRow, "Sling", 0, "", "Soft leather", 1, "") +
        sprintf(SkillsRow, "Splint armor", 2, "", "Staff", 3, "") +
        sprintf(SkillsRow, "Thrown", 4, "", "Two-handed sword", 5, "") +
        sprintf(HalfRow, "Unarmed", 6, "", "") + EndBar +
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
        sprintf(SkillsRow, "Axe", 0, "", "Bow", 1, "") +
        sprintf(SkillsRow, "Chainmail", 2, "", "Crossbow", 3, "") +
        sprintf(SkillsRow, "Dagger", 4, "", "Dodge", 5, "") +
        sprintf(SkillsRow, "Dual wield", 6, "", "Flail", 7, "") +
        sprintf(SkillsRow, "Hammer", 8, "", "Hand and a half sword", 9, "") +
        sprintf(SkillsRow, "Hard leather", 0, "", "Long sword", 1, "") +
        sprintf(SkillsRow, "Mace", 2, "", "No armor", 3, "") +
        sprintf(SkillsRow, "Parry", 4, "", "Plate armor", 5, "") +
        sprintf(SkillsRow, "Pole arm", 6, "", "Scalemail", 7, "") +
        sprintf(SkillsRow, "Shield", 8, "", "Short sword", 9, "") +
        sprintf(SkillsRow, "Sling", 0, "", "Soft leather", 1, "") +
        sprintf(SkillsRow, "Splint armor", 2, "", "Staff", 3, "") +
        sprintf(SkillsRow, "Thrown", 4, "", "Two-handed sword", 5, "") +
        sprintf(HalfRow, "Unarmed", 6, "", "") + EndBar +
        sprintf(SkillPoints, 8);

    ExpectTrue(Player->executeCommand("skills -co"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CraftingFlagOnlyDisplaysCraftingSkills()
{
    Player->addSkillPoints(184);
    PrepSkillsOfType("crafting");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Crafting Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Armorer", 0, "", "Blacksmithing", 1, "") +
        sprintf(SkillsRow, "Bowyer and fletcher", 2, "", "Carpentry", 3, "") +
        sprintf(SkillsRow, "Dancing", 4, "", "Gem crafting", 5, "") +
        sprintf(SkillsRow, "Instrument: bowed", 6, "", "Instrument: brass", 7, "") +
        sprintf(SkillsRow, "Instrument: percussion", 8, "", "Instrument: plucked", 9, "") +
        sprintf(SkillsRow, "Instrument: woodwind", 0, "", "Leatherworking", 1, "") +
        sprintf(SkillsRow, "Metal crafting", 2, "", "Mining", 3, "") +
        sprintf(SkillsRow, "Pottery", 4, "", "Sculpture", 5, "") +
        sprintf(SkillsRow, "Sewing", 6, "", "Singing", 7, "") +
        sprintf(SkillsRow, "Stonemasonry", 8, "", "Weapon smithing", 9, "") +
        sprintf(SkillsRow, "Weaving and beadwork", 0, "", "Wood crafting", 1, "") +
        EndBar + sprintf(SkillPoints, 2);

    ExpectTrue(Player->executeCommand("skills -crafting"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CrFlagOnlyDisplaysCraftingSkills()
{
    Player->addSkillPoints(184);
    PrepSkillsOfType("crafting");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Crafting Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Armorer", 0, "", "Blacksmithing", 1, "") +
        sprintf(SkillsRow, "Bowyer and fletcher", 2, "", "Carpentry", 3, "") +
        sprintf(SkillsRow, "Dancing", 4, "", "Gem crafting", 5, "") +
        sprintf(SkillsRow, "Instrument: bowed", 6, "", "Instrument: brass", 7, "") +
        sprintf(SkillsRow, "Instrument: percussion", 8, "", "Instrument: plucked", 9, "") +
        sprintf(SkillsRow, "Instrument: woodwind", 0, "", "Leatherworking", 1, "") +
        sprintf(SkillsRow, "Metal crafting", 2, "", "Mining", 3, "") +
        sprintf(SkillsRow, "Pottery", 4, "", "Sculpture", 5, "") +
        sprintf(SkillsRow, "Sewing", 6, "", "Singing", 7, "") +
        sprintf(SkillsRow, "Stonemasonry", 8, "", "Weapon smithing", 9, "") +
        sprintf(SkillsRow, "Weaving and beadwork", 0, "", "Wood crafting", 1, "") +
        EndBar + sprintf(SkillPoints, 2);

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
    Player->addSkillPoints(100);
    PrepSkillsOfType("subterfuge");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Subterfuge Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Climb", 0, "", "Direction sense", 1, "") +
        sprintf(SkillsRow, "Disable traps", 2, "", "Disguise", 3, "") +
        sprintf(SkillsRow, "Find traps", 4, "", "Hide", 5, "") +
        sprintf(SkillsRow, "Listen", 6, "", "Move silently", 7, "") +
        sprintf(SkillsRow, "Open lock", 8, "", "Search", 9, "") +
        sprintf(SkillsRow, "Set traps and snares", 0, "", "Spot", 1, "") +
        sprintf(HalfRow, "Tracking", 2, "", "") +
        EndBar + sprintf(SkillPoints, 4);

    ExpectTrue(Player->executeCommand("skills -subterfuge"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SFlagOnlyDisplaysSubterfugeSkills()
{
    Player->addSkillPoints(100);
    PrepSkillsOfType("subterfuge");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Subterfuge Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Climb", 0, "", "Direction sense", 1, "") +
        sprintf(SkillsRow, "Disable traps", 2, "", "Disguise", 3, "") +
        sprintf(SkillsRow, "Find traps", 4, "", "Hide", 5, "") +
        sprintf(SkillsRow, "Listen", 6, "", "Move silently", 7, "") +
        sprintf(SkillsRow, "Open lock", 8, "", "Search", 9, "") +
        sprintf(SkillsRow, "Set traps and snares", 0, "", "Spot", 1, "") +
        sprintf(HalfRow, "Tracking", 2, "", "") +
        EndBar + sprintf(SkillPoints, 4);

    ExpectTrue(Player->executeCommand("skills -s"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeneralFlagOnlyDisplaysGeneralSkills()
{
    Player->addSkillPoints(100);
    PrepSkillsOfType("general");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Agriculture", 0, "", "Animal handling", 1, "") +
        sprintf(SkillsRow, "Barter", 2, "", "Camp skills", 3, "") +
        sprintf(SkillsRow, "Cooking", 4, "", "Diplomacy", 5, "") +
        sprintf(SkillsRow, "Etiquette", 6, "", "Hunting", 7, "") +
        sprintf(SkillsRow, "Nautical skills", 8, "", "Persuasion", 9, "") +
        sprintf(SkillsRow, "Rope skills", 0, "", "Swimming", 1, "") +
        sprintf(HalfRow, "Weather sense", 2, "", "") +
        EndBar + sprintf(SkillPoints, 4);

    ExpectTrue(Player->executeCommand("skills -general"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GFlagOnlyDisplaysGeneralSkills()
{
    Player->addSkillPoints(100);
    PrepSkillsOfType("general");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Agriculture", 0, "", "Animal handling", 1, "") +
        sprintf(SkillsRow, "Barter", 2, "", "Camp skills", 3, "") +
        sprintf(SkillsRow, "Cooking", 4, "", "Diplomacy", 5, "") +
        sprintf(SkillsRow, "Etiquette", 6, "", "Hunting", 7, "") +
        sprintf(SkillsRow, "Nautical skills", 8, "", "Persuasion", 9, "") +
        sprintf(SkillsRow, "Rope skills", 0, "", "Swimming", 1, "") +
        sprintf(HalfRow, "Weather sense", 2, "", "") +
        EndBar + sprintf(SkillPoints, 4);

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
    Player->addSkillPoints(95);
    PrepSkillsOfType("language");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Language Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Andurathi", 0, "", "Common", 1, "") +
        sprintf(SkillsRow, "Dwarvish", 2, "", "Elvish", 3, "") +
        sprintf(SkillsRow, "Endurghul", 4, "", "High elvish", 5, "") +
        sprintf(SkillsRow, "Hillgarathi", 6, "", "Menadrosti", 7, "") +
        sprintf(SkillsRow, "Orcish", 8, "", "Sylvan", 9, "") +
        sprintf(HalfRow, "Tirnosti", 0, "", "") +
        EndBar + sprintf(SkillPoints, 5);

    ExpectTrue(Player->executeCommand("skills -language"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LFlagOnlyDisplaysLanguageSkills()
{
    Player->addSkillPoints(95);
    PrepSkillsOfType("language");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Language Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Andurathi", 0, "", "Common", 1, "") +
        sprintf(SkillsRow, "Dwarvish", 2, "", "Elvish", 3, "") +
        sprintf(SkillsRow, "Endurghul", 4, "", "High elvish", 5, "") +
        sprintf(SkillsRow, "Hillgarathi", 6, "", "Menadrosti", 7, "") +
        sprintf(SkillsRow, "Orcish", 8, "", "Sylvan", 9, "") +
        sprintf(HalfRow, "Tirnosti", 0, "", "") +
        EndBar + sprintf(SkillPoints, 5);

    ExpectTrue(Player->executeCommand("skills -l"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AllFlagDisplaysAllSkills()
{
    Player->addSkillPoints(1000);
    PrepSkillsOfType("combat");
    PrepSkillsOfType("crafting");
    PrepSkillsOfType("erudite");
    PrepSkillsOfType("subterfuge");
    PrepSkillsOfType("general");
    PrepSkillsOfType("magic");
    PrepSkillsOfType("language");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Combat Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Axe", 0, "", "Bow", 1, "") +
        sprintf(SkillsRow, "Chainmail", 2, "", "Crossbow", 3, "") +
        sprintf(SkillsRow, "Dagger", 4, "", "Dodge", 5, "") +
        sprintf(SkillsRow, "Dual wield", 6, "", "Flail", 7, "") +
        sprintf(SkillsRow, "Hammer", 8, "", "Hand and a half sword", 9, "") +
        sprintf(SkillsRow, "Hard leather", 0, "", "Long sword", 1, "") +
        sprintf(SkillsRow, "Mace", 2, "", "No armor", 3, "") +
        sprintf(SkillsRow, "Parry", 4, "", "Plate armor", 5, "") +
        sprintf(SkillsRow, "Pole arm", 6, "", "Scalemail", 7, "") +
        sprintf(SkillsRow, "Shield", 8, "", "Short sword", 9, "") +
        sprintf(SkillsRow, "Sling", 0, "", "Soft leather", 1, "") +
        sprintf(SkillsRow, "Splint armor", 2, "", "Staff", 3, "") +
        sprintf(SkillsRow, "Thrown", 4, "", "Two-handed sword", 5, "") +
        sprintf(HalfRow, "Unarmed", 6, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Crafting Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Armorer", 0, "", "Blacksmithing", 1, "") +
        sprintf(SkillsRow, "Bowyer and fletcher", 2, "", "Carpentry", 3, "") +
        sprintf(SkillsRow, "Dancing", 4, "", "Gem crafting", 5, "") +
        sprintf(SkillsRow, "Instrument: bowed", 6, "", "Instrument: brass", 7, "") +
        sprintf(SkillsRow, "Instrument: percussion", 8, "", "Instrument: plucked", 9, "") +
        sprintf(SkillsRow, "Instrument: woodwind", 0, "", "Leatherworking", 1, "") +
        sprintf(SkillsRow, "Metal crafting", 2, "", "Mining", 3, "") +
        sprintf(SkillsRow, "Pottery", 4, "", "Sculpture", 5, "") +
        sprintf(SkillsRow, "Sewing", 6, "", "Singing", 7, "") +
        sprintf(SkillsRow, "Stonemasonry", 8, "", "Weapon smithing", 9, "") +
        sprintf(SkillsRow, "Weaving and beadwork", 0, "", "Wood crafting", 1, "");

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
        sprintf(SkillsRow, "Nautical skills", 8, "", "Persuasion", 9, "") +
        sprintf(SkillsRow, "Rope skills", 0, "", "Swimming", 1, "") +
        sprintf(HalfRow, "Weather sense", 2, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Language Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Andurathi", 0, "", "Common", 1, "") +
        sprintf(SkillsRow, "Dwarvish", 2, "", "Elvish", 3, "") +
        sprintf(SkillsRow, "Endurghul", 4, "", "High elvish", 5, "") +
        sprintf(SkillsRow, "Hillgarathi", 6, "", "Menadrosti", 7, "") +
        sprintf(SkillsRow, "Orcish", 8, "", "Sylvan", 9, "") +
        sprintf(HalfRow, "Tirnosti", 0, "", "");

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
        sprintf(SkillsRow, "Climb", 0, "", "Direction sense", 1, "") +
        sprintf(SkillsRow, "Disable traps", 2, "", "Disguise", 3, "") +
        sprintf(SkillsRow, "Find traps", 4, "", "Hide", 5, "") +
        sprintf(SkillsRow, "Listen", 6, "", "Move silently", 7, "") +
        sprintf(SkillsRow, "Open lock", 8, "", "Search", 9, "") +
        sprintf(SkillsRow, "Set traps and snares", 0, "", "Spot", 1, "") +
        sprintf(HalfRow, "Tracking", 2, "", "") +
        EndBar + sprintf(SkillPoints, 20);

    ExpectTrue(Player->executeCommand("skills -all"));
    ExpectEq(message, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoFlagDisplaysAllSkills()
{
    Player->addSkillPoints(1000);
    PrepSkillsOfType("combat");
    PrepSkillsOfType("crafting");
    PrepSkillsOfType("erudite");
    PrepSkillsOfType("subterfuge");
    PrepSkillsOfType("general");
    PrepSkillsOfType("magic");
    PrepSkillsOfType("language");

    string message = "\n[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Combat Skills +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Axe", 0, "", "Bow", 1, "") +
        sprintf(SkillsRow, "Chainmail", 2, "", "Crossbow", 3, "") +
        sprintf(SkillsRow, "Dagger", 4, "", "Dodge", 5, "") +
        sprintf(SkillsRow, "Dual wield", 6, "", "Flail", 7, "") +
        sprintf(SkillsRow, "Hammer", 8, "", "Hand and a half sword", 9, "") +
        sprintf(SkillsRow, "Hard leather", 0, "", "Long sword", 1, "") +
        sprintf(SkillsRow, "Mace", 2, "", "No armor", 3, "") +
        sprintf(SkillsRow, "Parry", 4, "", "Plate armor", 5, "") +
        sprintf(SkillsRow, "Pole arm", 6, "", "Scalemail", 7, "") +
        sprintf(SkillsRow, "Shield", 8, "", "Short sword", 9, "") +
        sprintf(SkillsRow, "Sling", 0, "", "Soft leather", 1, "") +
        sprintf(SkillsRow, "Splint armor", 2, "", "Staff", 3, "") +
        sprintf(SkillsRow, "Thrown", 4, "", "Two-handed sword", 5, "") +
        sprintf(HalfRow, "Unarmed", 6, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Crafting Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Armorer", 0, "", "Blacksmithing", 1, "") +
        sprintf(SkillsRow, "Bowyer and fletcher", 2, "", "Carpentry", 3, "") +
        sprintf(SkillsRow, "Dancing", 4, "", "Gem crafting", 5, "") +
        sprintf(SkillsRow, "Instrument: bowed", 6, "", "Instrument: brass", 7, "") +
        sprintf(SkillsRow, "Instrument: percussion", 8, "", "Instrument: plucked", 9, "") +
        sprintf(SkillsRow, "Instrument: woodwind", 0, "", "Leatherworking", 1, "") +
        sprintf(SkillsRow, "Metal crafting", 2, "", "Mining", 3, "") +
        sprintf(SkillsRow, "Pottery", 4, "", "Sculpture", 5, "") +
        sprintf(SkillsRow, "Sewing", 6, "", "Singing", 7, "") +
        sprintf(SkillsRow, "Stonemasonry", 8, "", "Weapon smithing", 9, "") +
        sprintf(SkillsRow, "Weaving and beadwork", 0, "", "Wood crafting", 1, "");

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
        sprintf(SkillsRow, "Nautical skills", 8, "", "Persuasion", 9, "") +
        sprintf(SkillsRow, "Rope skills", 0, "", "Swimming", 1, "") +
        sprintf(HalfRow, "Weather sense", 2, "", "");

    message += "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Language Skills +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m" +
        sprintf(SkillsRow, "Andurathi", 0, "", "Common", 1, "") +
        sprintf(SkillsRow, "Dwarvish", 2, "", "Elvish", 3, "") +
        sprintf(SkillsRow, "Endurghul", 4, "", "High elvish", 5, "") +
        sprintf(SkillsRow, "Hillgarathi", 6, "", "Menadrosti", 7, "") +
        sprintf(SkillsRow, "Orcish", 8, "", "Sylvan", 9, "") +
        sprintf(HalfRow, "Tirnosti", 0, "", "");

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
        sprintf(SkillsRow, "Climb", 0, "", "Direction sense", 1, "") +
        sprintf(SkillsRow, "Disable traps", 2, "", "Disguise", 3, "") +
        sprintf(SkillsRow, "Find traps", 4, "", "Hide", 5, "") +
        sprintf(SkillsRow, "Listen", 6, "", "Move silently", 7, "") +
        sprintf(SkillsRow, "Open lock", 8, "", "Search", 9, "") +
        sprintf(SkillsRow, "Set traps and snares", 0, "", "Spot", 1, "") +
        sprintf(HalfRow, "Tracking", 2, "", "") +
        EndBar + sprintf(SkillPoints, 20);

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
        sprintf(SkillsRow, "Axe", 0, "", "Bow", 1, "(+1)") +
        sprintf(SkillsRow, "Chainmail", 2, "", "Crossbow", 3, "") +
        sprintf(SkillsRow, "Dagger", 4, "", "Dodge", 5, "") +
        sprintf(SkillsRow, "Dual wield", 6, "", "Flail", 7, "") +
        sprintf(SkillsRow, "Hammer", 8, "(+5)", "Hand and a half sword", 9, "") +
        sprintf(SkillsRow, "Hard leather", 0, "", "Long sword", 1, "(+3)") +
        sprintf(SkillsRow, "Mace", 2, "", "No armor", 3, "") +
        sprintf(SkillsRow, "Parry", 4, "", "Plate armor", 5, "") +
        sprintf(SkillsRow, "Pole arm", 6, "", "Scalemail", 7, "") +
        sprintf(SkillsRow, "Shield", 8, "", "Short sword", 9, "") +
        sprintf(SkillsRow, "Sling", 0, "", "Soft leather", 1, "") +
        sprintf(SkillsRow, "Splint armor", 2, "", "Staff", 3, "") +
        sprintf(SkillsRow, "Thrown", 4, "", "Two-handed sword", 5, "") +
        sprintf(HalfRow, "Unarmed", 6, "", "") + EndBar +
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
        sprintf(SkillsRow, "Axe", 0, "", "Bow", 1, "(+1)") +
        sprintf(SkillsRow, "Chainmail", 2, "", "Crossbow", 3, "") +
        sprintf(SkillsRow, "Dagger", 4, "", "Dodge", 5, "") +
        sprintf(SkillsRow, "Dual wield", 6, "", "Flail", 7, "") +
        sprintf(SkillsRow, "Hammer", 8, "", "Hand and a half sword", 9, "") +
        sprintf(SkillsRow, "Hard leather", 0, "", "Long sword", 1, "") +
        sprintf(SkillsRow, "Mace", 2, "", "No armor", 3, "") +
        sprintf(SkillsRow, "Parry", 4, "", "Plate armor", 5, "") +
        sprintf(SkillsRow, "Pole arm", 6, "", "Scalemail", 7, "") +
        sprintf(SkillsRow, "Shield", 8, "", "Short sword", 9, "") +
        sprintf(SkillsRow, "Sling", 0, "", "Soft leather", 1, "") +
        sprintf(SkillsRow, "Splint armor", 2, "", "Staff", 3, "") +
        sprintf(SkillsRow, "Thrown", 4, "", "Two-handed sword", 5, "") +
        sprintf(HalfRow, "Unarmed", 6, "", "") + EndBar +
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
        sprintf(SkillsRow, "Axe", 0, "", "Bow", 0, "") +
        sprintf(SkillsRow, "Chainmail", 0, "", "Crossbow", 0, "") +
        sprintf(SkillsRow, "Dagger", 0, "", "Dodge", 0, "") +
        sprintf(SkillsRow, "Dual wield", 0, "", "Flail", 0, "") +
        sprintf(SkillsRow, "Hammer", 0, "", "Hand and a half sword", 0, "") +
        sprintf(SkillsRow, "Hard leather", 0, "", "Long sword", 1, "") +
        sprintf(SkillsRow, "Mace", 0, "", "No armor", 0, "") +
        sprintf(SkillsRow, "Parry", 0, "", "Plate armor", 0, "") +
        sprintf(SkillsRow, "Pole arm", 0, "", "Scalemail", 0, "") +
        sprintf(SkillsRow, "Shield", 0, "", "Short sword", 0, "") +
        sprintf(SkillsRow, "Sling", 0, "", "Soft leather", 0, "") +
        sprintf(SkillsRow, "Splint armor", 0, "", "Staff", 0, "") +
        sprintf(SkillsRow, "Thrown", 0, "", "Two-handed sword", 0, "") +
        sprintf(HalfRow, "Unarmed", 0, "", "") + EndBar +
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
