//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "HallsOfJusticeConnectToTheSoutheastStreet",
        "JusticeResidentsHaveConversations",
        "EveryHallRoomLoads"
    }));
}

void Setup()
{
    Region = 0;
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    Harvested = ({});
    Spawned = ({});
}

void HallsOfJusticeConnectToTheSoutheastStreet()
{
    object street = load_object("/areas/eledhel/southern-city/20x7.c");
    object hall = clone_object(
        "/areas/eledhel/southern-city/halls-of-justice/0x0.c");
    object court = load_object(
        "/areas/eledhel/southern-city/halls-of-justice/0x1.c");
    object records = load_object(
        "/areas/eledhel/southern-city/halls-of-justice/1x0.c");
    object dining = load_object(
        "/areas/eledhel/southern-city/halls-of-justice/1x1.c");
    object chambers = load_object(
        "/areas/eledhel/southern-city/halls-of-justice/0x2.c");
    object study = load_object(
        "/areas/eledhel/southern-city/halls-of-justice/1x2.c");

    ExpectEq("/areas/eledhel/southern-city/halls-of-justice/0x0.c",
        street->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/southern-city/20x7.c",
        hall->getExitDirections()["default"]["north"]);
    ExpectTrue(street->isEnvironmentalElement("court house"));
    ExpectTrue(hall->isEnvironmentalElement("door"));
    ExpectEq("/areas/eledhel/southern-city/halls-of-justice/0x1.c",
        hall->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/halls-of-justice/1x0.c",
        hall->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/southern-city/halls-of-justice/0x2.c",
        court->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/southern-city/halls-of-justice/1x1.c",
        court->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/halls-of-justice/1x2.c",
        chambers->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/halls-of-justice/0x2.c",
        study->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/southern-city/halls-of-justice/0x1.c",
        dining->getExitDirections()["default"]["west"]);
    Harvested += ({ street, hall });
}

void JusticeResidentsHaveConversations()
{
    string *rooms = ({
        "/areas/eledhel/southern-city/halls-of-justice/0x0.c",
        "/areas/eledhel/southern-city/halls-of-justice/1x0.c",
        "/areas/eledhel/southern-city/halls-of-justice/1x1.c",
        "/areas/eledhel/southern-city/halls-of-justice/0x2.c"
    });
    string *residents = ({ "Melach", "Averin", "Ilyen", "Tavren" });
    string *topics = ({ "judgment", "petitions", "acolytes", "the petition" });
    int index;

    for (index = 0; index < sizeof(rooms); index++)
    {
        object room = clone_object(rooms[index]);
        object resident = 0;

        move_object(Player, room);
        foreach (object inhabitant in all_inventory(room))
        {
            if (inhabitant != Player && inhabitant->id(residents[index]))
            {
                resident = inhabitant;
                Spawned += ({ inhabitant });
            }
        }

        ExpectTrue(objectp(resident), residents[index]);
        ExpectTrue(resident->hasTopic(topics[index]) > -1, residents[index]);
        Harvested += ({ room });
    }
}

void EveryHallRoomLoads()
{
    string *rooms = ({
        "/areas/eledhel/southern-city/halls-of-justice/0x0.c",
        "/areas/eledhel/southern-city/halls-of-justice/0x1.c",
        "/areas/eledhel/southern-city/halls-of-justice/1x0.c",
        "/areas/eledhel/southern-city/halls-of-justice/1x1.c",
        "/areas/eledhel/southern-city/halls-of-justice/0x2.c",
        "/areas/eledhel/southern-city/halls-of-justice/1x2.c"
    });

    foreach (string roomPath in rooms)
    {
        ExpectTrue(objectp(load_object(roomPath)), roomPath);
    }
}
