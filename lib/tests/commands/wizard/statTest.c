//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Wizard;
object Catch;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    dataAccess.savePlayerData(database.GetWizardOfLevel("creator"));

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/environment.c");

    Catch = clone_object("/lib/tests/support/services/catchShadow.c");
    Wizard = clone_object("/lib/realizations/wizard.c");
    Wizard.restore("earl");
    Wizard.addCommands();
    Wizard.colorConfiguration("none");
    Catch.beginShadow(Wizard);

    setUsers(({ Wizard }));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Catch);
    destruct(Wizard);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void CanStatPlayers()
{
    Wizard.addExperience(200000);
    command("stat earl", Wizard);
    ExpectEq("Weasel Lord Earl the title-less\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Race: Elf                              Overall Level: Creator               |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "|   Hit Points: =====..... Spell Points: =====.....      Stamina: =====.....  |\n"
        "|              100/200                   120/235                 140/240      |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "|     Strength: 15    (+5) Intelligence: 12    (+1)       Wisdom: 13          |\n"
        "|    Dexterity: 13    (+1) Constitution: 15    (+1)     Charisma: 16    (+1)  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Guild: Fake mage                   Level: 16         Experience:  Level up  |\n"
        "| Guild: Blarg                       Level: 1          Experience:  Level up  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Primary Weapon: No Weapon       Attack: -25 to 75        Damage:   0 to 1   |\n"
        "|  Defend Attack:   1 to 1          Soak:   1 to 2   Encumberance:   0        |\n"
        "|          Wimpy:  70%         Hunted by: Nothing at all, aren't you lucky?   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Other Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| IP: ???               Age: 1 second                                         |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n", 
        Wizard.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanStatMonsters()
{
    object monster = clone_object("/lib/realizations/monster.c");
    monster.Race("human");
    monster.SetUpPersonaOfLevel("oneiromancer", 20);
    
    object item = clone_object("/lib/instances/items/weapons/staffs/ornate-staff.c");

    item.set("material", "malorn");
    item.set("name", "Staff of Weasels");
    item.set("short", "Staff of Weasels");
    item.set("identified", 1);
    item.set("craftsmanship", 120);
    item.set("primary damage type", "fire");
    item.set("crafting materials", (["metal":"kirnalt",
        "wood" : "malorn"]));

    move_object(item, monster);
    command("wield staff", monster);

    monster.Name("fred");
    move_object(monster, this_object());
    move_object(Wizard, this_object());
    command("stat fred", Wizard);
    ExpectEq("Fred \n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Race: Human                            Overall Level: 20                    |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "|   Hit Points: ========== Spell Points: ==========      Stamina: ==========  |\n"
        "|             1240/1240                 4240/4240               1240/1240     |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "|     Strength: 40         Intelligence: 40               Wisdom: 40          |\n"
        "|    Dexterity: 40         Constitution: 40             Charisma: 40          |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Persona Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| This character has the 'oneiromancer' persona.                              |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Primary Weapon: Staff of Wea... Attack:  22 to 122       Damage:  42 to 54  |\n"
        "| Offhand Weapon: Staff of Wea... Attack:  22 to 122       Damage:  42 to 54  |\n"
        "|  Defend Attack:  22 to 44         Soak:   7 to 14  Encumberance:   0        |\n"
        "|          Wimpy:   0%         Hunted by: Nothing at all, aren't you lucky?   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Other Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Filename: /lib/realizations/monster.c                                       |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n",
        Wizard.caughtMessage());

    destruct(item);
    destruct(monster);
}

/////////////////////////////////////////////////////////////////////////////
void CanStatAnItem()
{
    object item = clone_object("/lib/instances/items/weapons/staffs/ornate-staff.c");

    item.set("material", "malorn");
    item.set("name", "Staff of Weasels");
    item.set("short", "Staff of Weasels");
    item.set("identified", 1);
    item.set("craftsmanship", 120);
    item.set("primary damage type", "fire");
    item.set("crafting materials", (["metal":"kirnalt",
        "wood" : "malorn"]));

    move_object(item, Wizard);

    command("stat staff", Wizard);
    ExpectEq("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ File Information +=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Filename: /lib/instances/items/weapons/staffs/ornate-staff.c                |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-+ Detailed Information +=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "This is a roughly 5 foot long (152 cm) staff.\n"
        "This ornate staff is a masterwork item.\n"
        "    Material: Malorn\n"
        "    Attack: 22 to 122\n"
        "    Damage: 19 to 24 [+16 magical]\n"
        "    Defense: 15 to 20\n"
        "    Encumberance: 2\n"
        "    Weight: 4\n\n",
        Wizard.caughtMessage());
}
