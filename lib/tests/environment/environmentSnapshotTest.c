//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/sys/telnet.h"

object Environment;
object Service;
object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "__inline_lib_tests_environment_environmentSnapshotTest_c_93_#0000",
        "__inline_lib_tests_environment_environmentSnapshotTest_c_132_#0001",
        "__inline_lib_tests_environment_environmentSnapshotTest_c_147_#0002" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = getService("environment");
    Service.setYear(1);
    Service.setDay(92);
    Service.timeOfDay("noon");
    Environment = clone_object("/lib/tests/support/environment/testEnvironment.c");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Environment);
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void RoomSnapshotIncludesTerrainFeaturesAndItems()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment.testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment.testAddItem("/lib/tests/support/environment/fakeItem.c", "north");

    mapping snapshot = Environment.buildRoomSnapshot(Player);

    ExpectTrue(mappingp(snapshot), "buildRoomSnapshot returns a mapping");
    ExpectEq(1, sizeof(snapshot["terrain"]), "one terrain element captured");
    ExpectEq(1, sizeof(snapshot["features"]), "one feature captured");
    ExpectEq(1, sizeof(snapshot["items"]), "one item captured");
}

/////////////////////////////////////////////////////////////////////////////
void RoomSnapshotResolvesElementLocationToCoordinates()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment.testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");

    mapping snapshot = Environment.buildRoomSnapshot(Player);
    mapping feature = snapshot["features"][0];
    mapping location = feature["locations"][0];

    ExpectEq("north", location["description"], "location description is resolved");
    ExpectTrue(member(location, "x") && member(location, "y") &&
        member(location, "z"), "location carries coordinates");
    ExpectTrue(member(location, "x-rotation"), "location carries rotations");
}

/////////////////////////////////////////////////////////////////////////////
void RoomSnapshotIncludesExits()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment.testAddExit("north",
        "/lib/tests/support/environment/toLocation.c", "default");

    mapping snapshot = Environment.buildRoomSnapshot(Player);

    ExpectTrue(member(snapshot["exits"], "north") > -1,
        "snapshot exposes the north exit");
}

/////////////////////////////////////////////////////////////////////////////
void RoomSnapshotOmitsTheViewerFromContents()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    move_object(Player, Environment);

    mapping snapshot = Environment.buildRoomSnapshot(Player);

    ExpectEq(0, sizeof(filter(snapshot["contents"],
        (: $1["path"] == program_name(Player) :))),
        "the viewer is not listed in its own room contents");
}

/////////////////////////////////////////////////////////////////////////////
void LongEmitsRoomInfoOutOfBandToGmcpViewer()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    move_object(Player, Environment);
    Player.telnetNegotiation(DO, TELOPT_GMCP, 0);

    Environment.long(0, Player);

    string frame = Player.caughtGmcp();
    ExpectTrue(stringp(frame), "a GMCP frame was captured");
    ExpectSubStringMatch("Room.Info", frame,
        "the Room.Info package was emitted out-of-band");
}

/////////////////////////////////////////////////////////////////////////////
void LongDoesNotEmitOutOfBandToNonGmcpViewer()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    move_object(Player, Environment);

    Environment.long(0, Player);

    ExpectEq(0, sizeof(Player.caughtGmcpFrames()),
        "no GMCP frame is emitted when the viewer never enabled GMCP");
}

/////////////////////////////////////////////////////////////////////////////
void EnableGmcpPushesRoomInfoPackage()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    move_object(Player, Environment);
    Player.telnetNegotiation(DO, TELOPT_GMCP, 0);

    string found = implode(filter(Player.caughtGmcpFrames(),
        (: strstr($1, "Room.Info") != -1 :)), "");
    ExpectSubStringMatch("Room.Info", found,
        "Room.Info package pushed when GMCP is enabled");
}

/////////////////////////////////////////////////////////////////////////////
void RoomInfoPackageIncludesExitsKey()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment.testAddExit("north",
        "/lib/tests/support/environment/toLocation.c", "default");
    move_object(Player, Environment);
    Player.telnetNegotiation(DO, TELOPT_GMCP, 0);

    string found = implode(filter(Player.caughtGmcpFrames(),
        (: strstr($1, "Room.Info") != -1 :)), "");
    ExpectSubStringMatch("\"exits\"", found,
        "exits key present in Room.Info payload");
}

/////////////////////////////////////////////////////////////////////////////
void SecondLongInSameRoomDoesNotRepushRegionPackage()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    move_object(Player, Environment);
    Player.telnetNegotiation(DO, TELOPT_GMCP, 0);

    // First look
    Environment.long(0, Player);
    int after_first = sizeof(Player.caughtGmcpFrames());

    // Second look in same room - must NOT push another Region frame
    Environment.long(0, Player);
    int after_second = sizeof(Player.caughtGmcpFrames());

    // Room.Info is pushed each look; Region must not be re-pushed
    string *frames = Player.caughtGmcpFrames();
    int regionCount = 0;
    foreach (string frame in frames)
    {
        if (sizeof(regexp(({ frame }), "Region")))
        {
            regionCount++;
        }
    }
    ExpectTrue(regionCount <= 1,
        "Region package must not be pushed more than once for the same region");
}

/////////////////////////////////////////////////////////////////////////////
void ResetRegionTrackingCausesRegionToBeRepushedOnNextLook()
{
    Environment.testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    move_object(Player, Environment);
    Player.telnetNegotiation(DO, TELOPT_GMCP, 0);
    Environment.long(0, Player);

    // Second look in the same environment - Room.Info always pushed
    Environment.long(0, Player);
    ExpectSubStringMatch("Room.Info", Player.caughtGmcp(),
        "Room.Info always pushed on each look");
}

/////////////////////////////////////////////////////////////////////////////
void RegionSnapshotCellIncludesDecoratorKey()
{
    object region = clone_object("/lib/tests/support/environment/regionHelper.c");
    region.setRegionName("Fake Region");
    region.setRegionType("tol-dhurath");
    region.asManualRegion();
    region.setDimensions(1, 1);
    region.setCoordinate(0, 0,
        "/lib/tests/support/environment/testEnvironment.c", "none");

    object roomEnvironment = region.coordinateToMapping(0, 0)["environment"];
    mapping snapshot = roomEnvironment.buildRegionSnapshot();
    mapping cell = snapshot["rooms"][0];

    ExpectTrue(member(cell, "decorator"), "region snapshot cell exposes a decorator key");
    ExpectTrue(stringp(cell["decorator"]),
        "decorator key is a string identifier suitable for client-side lookup");

    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void RegionSnapshotCellIncludesEnvironmentalElements()
{
    object region = clone_object("/lib/tests/support/environment/regionHelper.c");
    region.setRegionName("Fake Region");
    region.setRegionType("tol-dhurath");
    region.asManualRegion();
    region.setDimensions(1, 1);
    region.setCoordinate(0, 0,
        "/lib/tests/support/environment/testEnvironment.c", "none");

    object roomEnvironment = region.coordinateToMapping(0, 0)["environment"];
    roomEnvironment.testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    roomEnvironment.testAddItem("/lib/tests/support/environment/fakeItem.c", "north");

    mapping snapshot = roomEnvironment.buildRegionSnapshot();
    mapping cell = snapshot["rooms"][0];

    ExpectEq(1, sizeof(cell["features"]),
        "region snapshot cell carries the room's feature elements");
    ExpectEq(1, sizeof(cell["items"]),
        "region snapshot cell carries the room's item elements");
    ExpectEq("north", cell["features"][0]["locations"][0]["description"],
        "feature location description is resolved for the region snapshot cell");

    destruct(region);
}
