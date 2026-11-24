//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include <functionlist.h>
inherit "/lib/tests/framework/testFixture.c";

object Region;
object Player;
object *Harvested = ({});
object *Spawned = ({});

protected void selectTestMethods(string *selectedTests)
{
    ignoreList -= selectedTests;

    foreach (string test in functionlist(this_object(),
        RETURN_FUNCTION_NAME | NAME_INHERITED))
    {
        if (member(selectedTests, test) < 0)
        {
            ignoreList += ({ test });
        }
    }
}

protected void runSelectedTests(string *selectedTests)
{
    for (int index = 0; index < sizeof(selectedTests); index++)
    {
        call_other(this_object(), selectedTests[index]);
        if (index < sizeof(selectedTests) - 1)
        {
            CleanUp();
            Setup();
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    selectTestMethods(({
        "FarmBeltHasConnectedAuthoredRoomsAndGraphicalDecorators",
        "CommonMeasureWayhouseConnectsStandYardAndRooms",
        "AbandonedCellarHasAConnectedFiveRoomLoop",
        "BoughcrossOrchardRoomsConnectToTheAccessLane",
        "BoughcrossResidentsAppearAtTheirWorksites",
        "LinwaethSmithyFacadeLoadsBeforeItsRegionIsValidated"
    }));
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Region = load_object("/areas/eledhel/central-rural/region.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    Harvested = ({});
    Spawned = ({});
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    foreach (object item in Harvested)
    {
        if (objectp(item))
        {
            destruct(item);
        }
    }
    foreach (object npc in Spawned)
    {
        if (objectp(npc))
        {
            destruct(npc);
        }
    }
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void FarmBeltHasConnectedAuthoredRoomsAndGraphicalDecorators()
{
    mapping rooms = ([]);
    mapping opposite = ([
        "north":"south",
        "south":"north",
        "east":"west",
        "west":"east"
    ]);
    for (int x = 0; x < Region->xDimension(); x++)
    {
        for (int y = 0; y < Region->yDimension(); y++)
        {
            mapping cell = Region->coordinateToMapping(x, y);
            if (mappingp(cell) && cell["is placed"])
            {
                rooms[cell["name"]] = cell["environment"];
            }
        }
    }
    ExpectEq(25, sizeof(rooms));
    foreach (string path, object room in rooms)
    {
        ExpectEq(-1, member(inherit_list(room),
            "/lib/environment/generatedEnvironment.c"), path);
        mapping snapshot = room->buildRoomSnapshot();
        ExpectEq(1, sizeof(snapshot["terrain"]) +
            sizeof(snapshot["interior"]), path);
        ExpectTrue(sizeof(snapshot["features"]) +
            sizeof(snapshot["items"]) > 0, path);
        string **icon = getService("region")->getMapIcon(Region,
            room->decoratorType(0), "none", "ascii");
        string rendered = "";
        foreach (string *row in icon)
        {
            rendered += implode(row, "");
        }
        ExpectTrue(rendered != "         ", path);
        foreach (string direction, string target in
            room->getExitDirections()["default"])
        {
            if (member(rooms, target))
            {
                ExpectEq(path, rooms[target]->getExitDirections()
                    ["default"][opposite[direction]], path);
            }
            else
            {
                ExpectTrue(objectp(load_object(target)), target);
            }
        }
    }
    string *pending = ({ "/areas/eledhel/central-rural/24x5.c" });
    mapping visited = ([]);
    while (sizeof(pending))
    {
        string path = pending[0];
        pending = pending[1..];
        if (!member(visited, path))
        {
            visited[path] = 1;
            foreach (string direction, string target in
                rooms[path]->getExitDirections()["default"])
            {
                if (member(rooms, target) && !member(visited, target))
                {
                    pending += ({ target });
                }
            }
        }
    }
    ExpectEq(25, sizeof(visited));
}

/////////////////////////////////////////////////////////////////////////////
void CommonMeasureWayhouseConnectsStandYardAndRooms()
{
    object stand = load_object("/areas/eledhel/central-rural/23x6.c");
    object yard = load_object("/areas/eledhel/central-rural/24x6.c");
    object stable = load_object("/areas/eledhel/central-rural/24x7.c");
    object inn = clone_object(
        "/areas/eledhel/central-rural/common-measure/inn.c");

    ExpectEq("/areas/eledhel/central-rural/24x6.c",
        stand->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-rural/23x6.c",
        yard->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-rural/24x7.c",
        yard->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/central-rural/24x6.c",
        stable->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/central-rural/common-measure/0x1.c",
        yard->getExitDirections()["default"]["east"]);
    ExpectTrue(yard->isEnvironmentalElement("plank door"));

    ExpectTrue(objectp(inn));
    if (objectp(inn))
    {
        ExpectTrue(mappingp(inn->coordinateToMapping(2, 2)));
        ExpectTrue(mappingp(inn->coordinateToMapping(2, 1)));
        ExpectTrue(mappingp(inn->coordinateToMapping(3, 2)));
        ExpectTrue(mappingp(inn->coordinateToMapping(3, 1)));
        object common = clone_object(
            "/areas/eledhel/central-rural/common-measure/0x1.c");
        object loft = clone_object(
            "/areas/eledhel/central-rural/common-measure/0x0.c");
        object kitchen = clone_object(
            "/areas/eledhel/central-rural/common-measure/1x1.c");
        object pantry = clone_object(
            "/areas/eledhel/central-rural/common-measure/1x0.c");

        ExpectTrue(objectp(common));
        ExpectTrue(objectp(loft));
        ExpectTrue(objectp(kitchen));
        ExpectTrue(objectp(pantry));
        if (objectp(common) && objectp(loft) && objectp(kitchen) &&
            objectp(pantry))
        {
            mapping commonExitData = common->getExitDirections();
            mapping commonExits = mappingp(commonExitData["default"]) ?
                commonExitData["default"] : ([]);
            mapping loftExitData = loft->getExitDirections();
            mapping loftExits = mappingp(loftExitData["default"]) ?
                loftExitData["default"] : ([]);
            mapping kitchenExitData = kitchen->getExitDirections();
            mapping kitchenExits =
                mappingp(kitchenExitData["default"]) ?
                    kitchenExitData["default"] : ([]);
            mapping pantryExitData = pantry->getExitDirections();
            mapping pantryExits = mappingp(pantryExitData["default"]) ?
                pantryExitData["default"] : ([]);

            ExpectEq("/areas/eledhel/central-rural/24x6.c",
                commonExits["west"]);
            ExpectTrue(common->isEnvironmentalElement("plank door"));

            ExpectEq("/areas/eledhel/central-rural/common-measure/1x1.c",
                commonExits["east"]);
            ExpectEq("/areas/eledhel/central-rural/common-measure/0x0.c",
                commonExits["north"]);
            ExpectEq("/areas/eledhel/central-rural/common-measure/1x0.c",
                kitchenExits["north"]);
            ExpectEq("/areas/eledhel/central-rural/common-measure/0x1.c",
                loftExits["south"]);
            ExpectEq("/areas/eledhel/central-rural/common-measure/1x1.c",
                pantryExits["south"]);
            ExpectEq("/areas/eledhel/central-rural/24x6.c",
                inn->entryPoint());
            ExpectEq("west", inn->entryDirection());
        }
        destruct(common);
        destruct(loft);
        destruct(kitchen);
        destruct(pantry);
        destruct(inn);
    }
}

/////////////////////////////////////////////////////////////////////////////
void AbandonedCellarHasAConnectedFiveRoomLoop()
{
    object region = clone_object(
        "/areas/eledhel/central-rural/cellar/region.c");
    object outside = clone_object(
        "/areas/eledhel/central-rural/23x8.c");
    object entry = clone_object(
        "/areas/eledhel/central-rural/cellar/2x2.c");
    object store = clone_object(
        "/areas/eledhel/central-rural/cellar/2x1.c");
    object vault = clone_object(
        "/areas/eledhel/central-rural/cellar/3x1.c");
    object sump = clone_object(
        "/areas/eledhel/central-rural/cellar/3x2.c");
    object cache = clone_object(
        "/areas/eledhel/central-rural/cellar/1x1.c");

    ExpectEq("/areas/eledhel/central-rural/cellar/2x2.c",
        region->coordinateToMapping(2, 2)["name"]);
    ExpectEq("/areas/eledhel/central-rural/cellar/1x1.c",
        region->coordinateToMapping(1, 1)["name"]);
    ExpectEq("/areas/eledhel/central-rural/23x8.c", region->entryPoint());
    ExpectEq("west", region->entryDirection());

    ExpectEq("/areas/eledhel/central-rural/cellar/2x2.c",
        outside->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-rural/23x8.c",
        entry->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-rural/cellar/2x1.c",
        entry->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/central-rural/cellar/3x2.c",
        entry->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-rural/cellar/1x1.c",
        store->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-rural/cellar/3x1.c",
        store->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-rural/cellar/3x2.c",
        vault->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/central-rural/cellar/3x1.c",
        sump->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/central-rural/cellar/2x2.c",
        sump->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/central-rural/cellar/2x1.c",
        cache->getExitDirections()["default"]["east"]);
    ExpectTrue(outside->isEnvironmentalElement("plank door"));
    ExpectTrue(entry->isEnvironmentalElement("plank door"));
    ExpectTrue(cache->isEnvironmentalElement("farm tally board"));

    destruct(outside);
    destruct(entry);
    destruct(store);
    destruct(vault);
    destruct(sump);
    destruct(cache);
    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void BoughcrossOrchardRoomsConnectToTheAccessLane()
{
    object region = clone_object("/areas/eledhel/west-rural/region.c");
    object lane = load_object("/areas/eledhel/west-rural/23x0.c");
    object apiary = clone_object("/areas/eledhel/west-rural/23x1.c");
    object square = clone_object("/areas/eledhel/west-rural/23x2.c");
    object cooperage = clone_object(
        "/areas/eledhel/west-rural/orchard-hamlet/cooperage.c");
    object crossroads = load_object("/areas/eledhel/west-rural/22x2.c");

    ExpectEq("/areas/eledhel/west-rural/23x1.c",
        region->coordinateToMapping(23, 1)["name"]);
    ExpectEq("/areas/eledhel/west-rural/23x2.c",
        region->coordinateToMapping(23, 2)["name"]);
    ExpectEq("/areas/eledhel/west-rural/23x2.c",
        crossroads->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/west-rural/22x2.c",
        square->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/west-rural/23x1.c",
        square->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/west-rural/23x2.c",
        apiary->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/west-rural/23x0.c",
        apiary->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/west-rural/23x1.c",
        lane->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/west-rural/orchard-hamlet/cooperage.c",
        square->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/west-rural/23x2.c",
        cooperage->getExitDirections()["default"]["west"]);
    ExpectTrue(apiary->isEnvironmentalElement("hive splinters"));
    ExpectTrue(square->isEnvironmentalElement("orchard access board"));
    ExpectTrue(cooperage->isEnvironmentalElement("cask hoops"));
    ExpectTrue(square->isEnvironmentalElement("plank door"));
    ExpectTrue(cooperage->isEnvironmentalElement("plank door"));

    foreach (object room in ({ apiary, square, cooperage }))
    {
        foreach (object resident in all_inventory(room))
        {
            if (function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                Spawned += ({ resident });
            }
        }
    }

    destruct(lane);
    destruct(apiary);
    destruct(square);
    destruct(cooperage);
    destruct(crossroads);
    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void BoughcrossResidentsAppearAtTheirWorksites()
{
    mapping residents = ([
        "/areas/eledhel/west-rural/23x2.c":"Meral",
        "/areas/eledhel/west-rural/23x1.c":"Vessa",
        "/areas/eledhel/west-rural/orchard-hamlet/cooperage.c":"Derrik"
    ]);

    foreach (string path, string name in residents)
    {
        object room = clone_object(path);
        move_object(Player, room);
        int residentCount = 0;
        foreach (object resident in all_inventory(room))
        {
            if (resident != Player &&
                function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                ExpectTrue(resident->id(name), path);
                residentCount++;
                Spawned += ({ resident });
            }
        }
        ExpectEq(1, residentCount, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void LinwaethSmithyFacadeLoadsBeforeItsRegionIsValidated()
{
    object smith = load_object("/areas/linwaeth/13x3.c");

    ExpectTrue(member(inherit_list(smith),
        "/lib/environment/environment.c") >= 0);
    ExpectTrue(smith->isEnvironmentalElement("plank door"));
}

/////////////////////////////////////////////////////////////////////////////
protected void validateAuthoredRegions(string *regionPaths)
{
    object validator = clone_object(
        "/lib/tests/support/environment/authoredRegionValidator.c");
    string *errors = validator->validateRegions(regionPaths);

    ExpectEq(({}), errors);
    destruct(validator);
}

void AuthoredCoreRegionsValidate()
{
    validateAuthoredRegions(({
        "/areas/argalen-keep/surrounding/region.c",
        "/areas/argalen-keep/patrol-woods/region.c",
        "/areas/argalen-keep/patrol-coast/region.c",
        "/areas/argalen-keep/keep-interior/region.c",
        "/areas/eledhel/central-rural/region.c",
        "/areas/eledhel/estates/aladain/grounds/region.c",
        "/areas/eledhel/estates/aladain/keep-interior/region.c",
        "/areas/evenholt/river-celebuin/region.c",
        "/areas/eledhel/vargath-keep/approach/region.c",
        "/areas/eledhel/vargath-keep/limestone-caves/region.c",
        "/areas/eledhel/vargath-keep/canyon/region.c",
        "/areas/eledhel/vargath-keep/keep-interior/region.c",
        "/areas/linwaeth/looming-stag/region.c",
        "/areas/linwaeth/smithy/region.c",
        "/areas/linwaeth/region.c"
    }));
}

void SouthernRoadRegionsValidate()
{
    validateAuthoredRegions(({
        "/areas/eledhel/south-rural-route-01/region.c",
        "/areas/eledhel/south-rural-route-02/region.c",
        "/areas/eledhel/south-rural-route-03/region.c",
        "/areas/eledhel/south-rural-route-04/region.c",
        "/areas/eledhel/south-rural-route-05/region.c",
        "/areas/eledhel/south-rural-route-06/region.c",
        "/areas/eledhel/south-rural-route-07/region.c",
        "/areas/eledhel/south-rural-route-08/region.c",
        "/areas/eledhel/tirwen/region.c",
        "/areas/eledhel/tirwen/farmhouse/region.c",
        "/areas/eledhel/dhorlen/region.c",
        "/areas/eledhel/dhorlen/mill/region.c",
        "/areas/eledhel/hadrath/watchlands/region.c",
        "/areas/eledhel/hadrath/grounds/region.c",
        "/areas/eledhel/hadrath/keep-interior/region.c",
        "/areas/eledhel/southwest-rural-four/region.c"
    }));
}

void SouthernCoastRegionsValidate()
{
    validateAuthoredRegions(({
        "/areas/eledhel/south-rural-route-09/region.c",
        "/areas/eledhel/south-rural-route-10/region.c",
        "/areas/eledhel/south-rural-route-11/region.c",
        "/areas/eledhel/south-rural-route-12/region.c",
        "/areas/eledhel/south-rural-route-13/region.c",
        "/areas/eledhel/south-rural-route-14/region.c",
        "/areas/eledhel/south-rural-route-15/region.c",
        "/areas/eledhel/south-rural-route-16/region.c",
        "/areas/eledhel/south-rural-route-17/region.c",
        "/areas/eledhel/southwest-rural-five/region.c",
        "/areas/eledhel/south-coast-one/region.c",
        "/areas/eledhel/south-coast-two/region.c",
        "/areas/eledhel/south-coast-two/cove-cave/region.c",
        "/areas/eledhel/rhaedhen/region.c",
        "/areas/anor/region.c"
    }));
}

void CapitalAndMinlachRegionsValidate()
{
    validateAuthoredRegions(({
        "/areas/eledhel/northern-city/phaedra-headquarters/region.c",
        "/areas/eledhel/northern-city/prison/region.c",
        "/areas/eledhel/northern-city/arena/region.c",
        "/areas/minlach/region.c",
        "/areas/minlach/surrounding/region.c",
        "/areas/minlach/shore/region.c"
    }));
}

void SouthernManorRegionsValidate()
{
    object validator = clone_object(
        "/lib/tests/support/environment/authoredRegionValidator.c");
    string *errors = validator->validateRegions(({
        "/areas/eledhel/estates/oeldhen/grounds/region.c",
        "/areas/eledhel/estates/oeldhen/manor-interior/region.c",
        "/areas/eledhel/estates/llenwych/grounds/region.c",
        "/areas/eledhel/estates/llenwych/manor-interior/region.c",
        "/areas/eledhel/estates/urdhan/grounds/region.c",
        "/areas/eledhel/estates/urdhan/manor-interior/region.c",
        "/areas/eledhel/estates/hador/grounds/region.c",
        "/areas/eledhel/estates/hador/manor-interior/region.c",
        "/areas/eledhel/estates/endur/grounds/region.c",
        "/areas/eledhel/estates/endur/manor-interior/region.c",
        "/areas/eledhel/estates/celedrath/grounds/region.c",
        "/areas/eledhel/estates/celedrath/manor-interior/region.c"
    }));

    ExpectEq(({}), errors);
    destruct(validator);
}

/////////////////////////////////////////////////////////////////////////////
void SouthernRoadConnectsTheCountrysideAndItsManorBranches()
{
    mapping opposite = ([
        "north":"south",
        "south":"north",
        "east":"west",
        "west":"east"
    ]);
    mapping links = ([
        "/areas/eledhel/southwest-rural-one/24x0.c":
            (["east": "/areas/eledhel/southern-rural/0x7.c"]),
        "/areas/eledhel/southwest-rural-one/0x2.c":
            (["west": "/areas/eledhel/southwest-rural-two/24x3.c"]),
        "/areas/eledhel/southwest-rural-two/0x2.c":
            (["east": "/areas/eledhel/south-rural-route-01/0x2.c"]),
        "/areas/eledhel/south-rural-route-01/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-02/0x2.c"]),
        "/areas/eledhel/south-rural-route-02/24x2.c":
            (["south": "/areas/eledhel/south-rural-route-03/24x2.c"]),
        "/areas/eledhel/south-rural-route-03/0x2.c":
            (["north": "/areas/eledhel/southwest-rural-three/24x0.c"]),
        "/areas/eledhel/southwest-rural-three/17x4.c":
            (["south": "/areas/eledhel/south-rural-route-04/0x2.c"]),
        "/areas/eledhel/south-rural-route-04/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-05/0x2.c"]),
        "/areas/eledhel/south-rural-route-05/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-06/0x2.c"]),
        "/areas/eledhel/south-rural-route-06/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-07/0x2.c"]),
        "/areas/eledhel/south-rural-route-07/24x2.c":
            (["south": "/areas/eledhel/southwest-rural-four/12x0.c"]),
        "/areas/eledhel/southwest-rural-three/12x3.c":
            (["north": "/areas/eledhel/rhaedhen/0x2.c"]),
        "/areas/eledhel/rhaedhen/0x2.c":
            (["south": "/areas/eledhel/southwest-rural-three/12x3.c"]),
        "/areas/eledhel/southern-rural/2x6.c":
            (["north": "/areas/eledhel/estates/urdhan/grounds/0x2.c"]),
        "/areas/eledhel/southwest-rural-one/11x3.c":
            (["north": "/areas/eledhel/estates/hador/grounds/0x2.c"]),
        "/areas/eledhel/southwest-rural-two/12x1.c":
            (["west": "/areas/eledhel/estates/endur/grounds/0x2.c"]),
        "/areas/eledhel/estates/urdhan/grounds/0x2.c":
            (["south": "/areas/eledhel/southern-rural/2x6.c"]),
        "/areas/eledhel/estates/hador/grounds/0x2.c":
            (["south": "/areas/eledhel/southwest-rural-one/11x3.c"]),
        "/areas/eledhel/estates/endur/grounds/0x2.c":
            (["east": "/areas/eledhel/southwest-rural-two/12x1.c"]),
        "/areas/eledhel/southwest-rural-four/24x9.c":
            (["east": "/areas/eledhel/south-rural-route-08/0x2.c"]),
        "/areas/eledhel/south-rural-route-08/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-09/0x2.c"]),
        "/areas/eledhel/south-rural-route-09/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-10/0x2.c"]),
        "/areas/eledhel/south-rural-route-10/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-11/0x2.c"]),
        "/areas/eledhel/south-rural-route-11/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-12/0x2.c"]),
        "/areas/eledhel/south-rural-route-12/24x2.c":
            (["east": "/areas/eledhel/southwest-rural-five/0x4.c"]),
        "/areas/eledhel/southwest-rural-five/14x9.c":
            (["south": "/areas/eledhel/south-rural-route-13/0x2.c"]),
        "/areas/eledhel/south-rural-route-13/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-14/0x2.c"]),
        "/areas/eledhel/south-rural-route-14/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-15/0x2.c"]),
        "/areas/eledhel/south-rural-route-15/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-16/0x2.c"]),
        "/areas/eledhel/south-rural-route-16/24x2.c":
            (["east": "/areas/eledhel/south-rural-route-17/0x2.c"]),
        "/areas/eledhel/south-rural-route-17/21x2.c":
            (["south": "/areas/linwaeth/12x0.c"]),
        "/areas/linwaeth/12x0.c":
            (["north": "/areas/eledhel/south-rural-route-17/21x2.c"]),
        "/areas/eledhel/southern-rural/4x6.c":
            (["east": "/areas/eledhel/estates/oeldhen/grounds/0x2.c"]),
        "/areas/eledhel/southwest-rural-one/13x1.c":
            (["west": "/areas/eledhel/estates/llenwych/grounds/0x2.c"]),
        "/areas/eledhel/southwest-rural-three/20x3.c":
            (["west": "/areas/eledhel/estates/celedrath/grounds/0x2.c"])
    ]);

    foreach (string path, mapping expectedExits in links)
    {
        object room = load_object(path);
        mapping exits = room->getExitDirections()["default"];
        foreach (string direction, string target in expectedExits)
        {
            ExpectEq(target, exits[direction], path);
            object destination = load_object(target);
            mapping returnExits =
                destination->getExitDirections()["default"];
            ExpectEq(path, returnExits[opposite[direction]], target);
        }
    }

    object *regions = ({
        load_object("/areas/eledhel/southern-rural/region.c"),
        load_object("/areas/eledhel/southwest-rural-one/region.c"),
        load_object("/areas/eledhel/southwest-rural-two/region.c"),
        load_object("/areas/eledhel/southwest-rural-three/region.c"),
        load_object("/areas/eledhel/southwest-rural-four/region.c"),
        load_object("/areas/eledhel/southwest-rural-five/region.c")
    });
    foreach (object region in regions)
    {
        ExpectTrue(region->xDimension() <= 25);
        ExpectTrue(region->yDimension() <= 10);
    }
    ExpectEq("southwest-rural-three", regions[3]->regionName());
    ExpectEq(25, regions[4]->xDimension());
    ExpectEq(10, regions[4]->yDimension());
    ExpectEq(25, regions[5]->xDimension());
    ExpectEq(10, regions[5]->yDimension());
    ExpectEq("Linwaeth wool commons and approach",
        regions[5]->regionName());
}

/////////////////////////////////////////////////////////////////////////////
protected int shortestRoomPathInRegion(object region, string start,
    string finish)
{
    mapping localRooms = ([]);
    mapping distances = ([ start: 0 ]);
    string *pending = ({ start });
    string *visited = ({ start });
    int result = -1;

    for (int x = 0; x < region->xDimension(); x++)
    {
        for (int y = 0; y < region->yDimension(); y++)
        {
            mapping coordinate = region->coordinateToMapping(x, y);
            if (mappingp(coordinate) && coordinate["is placed"])
            {
                localRooms[coordinate["name"]] = 1;
            }
        }
    }

    while (sizeof(pending))
    {
        string current = pending[0];
        pending = pending[1..];

        if (current != finish)
        {
            object room = load_object(current);
            mapping exitData = room->getExitDirections();
            mapping exits = mappingp(exitData) ?
                exitData["default"] : 0;

            if (mappingp(exits))
            {
                foreach (string target in m_values(exits))
                {
                    if (member(localRooms, target) &&
                        (member(visited, target) < 0))
                    {
                        distances[target] = distances[current] + 1;
                        pending += ({ target });
                        visited += ({ target });
                    }
                }
            }
        }
    }

    if (member(localRooms, finish) && member(visited, finish) >= 0)
    {
        result = distances[finish];
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
void SouthernRoadStagesHaveTwentyRoomThroughRoutes()
{
    object droveRegion = load_object(
        "/areas/eledhel/southwest-rural-four/region.c");
    object woolRegion = load_object(
        "/areas/eledhel/southwest-rural-five/region.c");
    string droveStart =
        "/areas/eledhel/southwest-rural-four/12x0.c";
    string droveEnd =
        "/areas/eledhel/southwest-rural-four/24x9.c";
    string woolStart =
        "/areas/eledhel/southwest-rural-five/0x4.c";
    string woolEnd =
        "/areas/eledhel/southwest-rural-five/14x9.c";

    ExpectTrue(shortestRoomPathInRegion(droveRegion, droveStart, droveEnd)
        >= 19, "The drove-country route must span at least 20 rooms.");
    ExpectTrue(shortestRoomPathInRegion(woolRegion, woolStart, woolEnd)
        >= 19, "The wool-country route must span at least 20 rooms.");
}

/////////////////////////////////////////////////////////////////////////////
void EledhelLinwaethRouteMeasuresAtLeastOneThousandFeetPerRoadRoom()
{
    string *regions = ({
        "/areas/eledhel/southern-rural/region.c",
        "/areas/eledhel/southwest-rural-one/region.c",
        "/areas/eledhel/southwest-rural-two/region.c",
        "/areas/eledhel/south-rural-route-01/region.c",
        "/areas/eledhel/south-rural-route-02/region.c",
        "/areas/eledhel/south-rural-route-03/region.c",
        "/areas/eledhel/southwest-rural-three/region.c",
        "/areas/eledhel/south-rural-route-04/region.c",
        "/areas/eledhel/south-rural-route-05/region.c",
        "/areas/eledhel/south-rural-route-06/region.c",
        "/areas/eledhel/south-rural-route-07/region.c",
        "/areas/eledhel/southwest-rural-four/region.c",
        "/areas/eledhel/south-rural-route-08/region.c",
        "/areas/eledhel/south-rural-route-09/region.c",
        "/areas/eledhel/south-rural-route-10/region.c",
        "/areas/eledhel/south-rural-route-11/region.c",
        "/areas/eledhel/south-rural-route-12/region.c",
        "/areas/eledhel/southwest-rural-five/region.c",
        "/areas/eledhel/south-rural-route-13/region.c",
        "/areas/eledhel/south-rural-route-14/region.c",
        "/areas/eledhel/south-rural-route-15/region.c",
        "/areas/eledhel/south-rural-route-16/region.c",
        "/areas/eledhel/south-rural-route-17/region.c"
    });
    string *starts = ({
        "/areas/eledhel/southern-rural/3x9.c",
        "/areas/eledhel/southwest-rural-one/24x0.c",
        "/areas/eledhel/southwest-rural-two/24x3.c",
        "/areas/eledhel/south-rural-route-01/0x2.c",
        "/areas/eledhel/south-rural-route-02/0x2.c",
        "/areas/eledhel/south-rural-route-03/24x2.c",
        "/areas/eledhel/southwest-rural-three/24x0.c",
        "/areas/eledhel/south-rural-route-04/0x2.c",
        "/areas/eledhel/south-rural-route-05/0x2.c",
        "/areas/eledhel/south-rural-route-06/0x2.c",
        "/areas/eledhel/south-rural-route-07/0x2.c",
        "/areas/eledhel/southwest-rural-four/12x0.c",
        "/areas/eledhel/south-rural-route-08/0x2.c",
        "/areas/eledhel/south-rural-route-09/0x2.c",
        "/areas/eledhel/south-rural-route-10/0x2.c",
        "/areas/eledhel/south-rural-route-11/0x2.c",
        "/areas/eledhel/south-rural-route-12/0x2.c",
        "/areas/eledhel/southwest-rural-five/0x4.c",
        "/areas/eledhel/south-rural-route-13/0x2.c",
        "/areas/eledhel/south-rural-route-14/0x2.c",
        "/areas/eledhel/south-rural-route-15/0x2.c",
        "/areas/eledhel/south-rural-route-16/0x2.c",
        "/areas/eledhel/south-rural-route-17/0x2.c"
    });
    string *finishes = ({
        "/areas/eledhel/southern-rural/0x7.c",
        "/areas/eledhel/southwest-rural-one/0x2.c",
        "/areas/eledhel/southwest-rural-two/0x2.c",
        "/areas/eledhel/south-rural-route-01/24x2.c",
        "/areas/eledhel/south-rural-route-02/24x2.c",
        "/areas/eledhel/south-rural-route-03/0x2.c",
        "/areas/eledhel/southwest-rural-three/17x4.c",
        "/areas/eledhel/south-rural-route-04/24x2.c",
        "/areas/eledhel/south-rural-route-05/24x2.c",
        "/areas/eledhel/south-rural-route-06/24x2.c",
        "/areas/eledhel/south-rural-route-07/24x2.c",
        "/areas/eledhel/southwest-rural-four/24x9.c",
        "/areas/eledhel/south-rural-route-08/24x2.c",
        "/areas/eledhel/south-rural-route-09/24x2.c",
        "/areas/eledhel/south-rural-route-10/24x2.c",
        "/areas/eledhel/south-rural-route-11/24x2.c",
        "/areas/eledhel/south-rural-route-12/24x2.c",
        "/areas/eledhel/southwest-rural-five/14x9.c",
        "/areas/eledhel/south-rural-route-13/24x2.c",
        "/areas/eledhel/south-rural-route-14/24x2.c",
        "/areas/eledhel/south-rural-route-15/24x2.c",
        "/areas/eledhel/south-rural-route-16/24x2.c",
        "/areas/eledhel/south-rural-route-17/21x2.c"
    });
    int totalRooms = 0;
    string routeSummary = "";

    for (int index = 0; index < sizeof(regions); index++)
    {
        object region = load_object(regions[index]);
        int routeLength = shortestRoomPathInRegion(region, starts[index],
            finishes[index]);
        ExpectTrue(routeLength >= 0, regions[index]);
        totalRooms += routeLength + 1;
        routeSummary += sprintf("%s%d",
            index ? ", " : "", routeLength + 1);
    }

    ExpectEq(555, totalRooms,
        sprintf("Route segment rooms: %s. Total %d.",
            routeSummary, totalRooms));
}

/////////////////////////////////////////////////////////////////////////////
void SouthernBackcountryPoolsHaveBoundedWildlifeAndOutlaws()
{
    string *regionPaths = ({
        "/areas/eledhel/southwest-rural-one/region.c",
        "/areas/eledhel/southwest-rural-two/region.c",
        "/areas/eledhel/southwest-rural-three/region.c",
        "/areas/eledhel/southwest-rural-four/region.c",
        "/areas/eledhel/southwest-rural-five/region.c"
    });
    string *locations = ({
        "11x3", "18x2", "10x3", "14x5", "3x2"
    });
    int *levels = ({ 2, 3, 2, 3, 4 });

    for (int index = 0; index < sizeof(regionPaths); index++)
    {
        object region = clone_object(regionPaths[index]);
        ExpectEq(levels[index], region->regionLevel(), regionPaths[index]);
        object room = region->getEnvironment(locations[index]);
        move_object(Player, room);

        int count = 0;
        foreach (object encounter in all_inventory(room))
        {
            if (encounter != Player &&
                function_exists("isRealizationOfMonster", encounter) &&
                encounter->isRealizationOfMonster())
            {
                int level = encounter->effectiveLevel();
                ExpectTrue(level >= 1 && level <= 5,
                    sprintf("%s encounter %s has level %d",
                        regionPaths[index], encounter->Name(), level));
                count++;
                Harvested += ({ encounter });
            }
        }
        ExpectTrue(count >= 1 && count <= 3,
            sprintf("%s has %d encounters",
                regionPaths[index], count));
        destruct(region);
    }
}

/////////////////////////////////////////////////////////////////////////////
void SouthernManorsUseAuthoredHoldingsAndRemainNpcOwned()
{
    object service = getService("domain");
    string *holdings = ({
        "house oeldhen",
        "house llenwych",
        "house urdhan",
        "house hador",
        "house endur",
        "house celedrath"
    });
    string *identifiers = ({
        "house-oeldhen",
        "house-llenwych",
        "house-urdhan",
        "house-hador",
        "house-endur",
        "house-celedrath"
    });
    string *entries = ({
        "/areas/eledhel/estates/oeldhen/grounds/0x2.c",
        "/areas/eledhel/estates/llenwych/grounds/0x2.c",
        "/areas/eledhel/estates/urdhan/grounds/0x2.c",
        "/areas/eledhel/estates/hador/grounds/0x2.c",
        "/areas/eledhel/estates/endur/grounds/0x2.c",
        "/areas/eledhel/estates/celedrath/grounds/0x2.c"
    });

    for (int index = 0; index < sizeof(holdings); index++)
    {
        mapping holding = service->getAuthoredHolding(holdings[index]);
        ExpectTrue(mappingp(holding), holdings[index]);
        ExpectEq(identifiers[index], holding["id"], holdings[index]);
        ExpectEq("Eledhel", holding["allegiance"], holdings[index]);
        ExpectEq(entries[index], holding["entry point"], holdings[index]);
        ExpectEq("keep", holding["type"], holdings[index]);
        ExpectFalse(service->getPlayerHolding(Player, holdings[index]),
            holdings[index]);

        mapping domain = service->getPlayerDomain(
            Player, holdings[index], holding["type"]);
        ExpectEq("keep", domain["type"], holdings[index]);
        ExpectTrue(sizeof(domain["layout"]) > 0, holdings[index]);
    }
}

/////////////////////////////////////////////////////////////////////////////
void SouthernNobleHouseholdStaffArePresent()
{
    mapping residents = ([
        "/areas/eledhel/estates/urdhan/manor-interior/1x1.c": "Maereth",
        "/areas/eledhel/estates/hador/manor-interior/1x1.c": "Haldren",
        "/areas/eledhel/estates/endur/manor-interior/1x1.c": "Endrath"
    ]);

    foreach (string path, string name in residents)
    {
        object room = clone_object(path);
        Harvested += ({ room });
        int foundResident = 0;
        move_object(Player, room);
        foreach (object resident in all_inventory(room))
        {
            if (function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                if (resident->id(name))
                {
                    foundResident = 1;
                }
                Spawned += ({ resident });
            }
        }
        ExpectTrue(foundResident, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void RhaedhenResidentsAppearAtTheirWorksites()
{
    mapping residents = ([
        "/areas/eledhel/rhaedhen/3x2.c": "Taleth",
        "/areas/eledhel/rhaedhen/2x3.c": "Calendir"
    ]);

    foreach (string path, string name in residents)
    {
        object room = clone_object(path);
        Harvested += ({ room });
        int foundResident = 0;
        move_object(Player, room);
        foreach (object resident in all_inventory(room))
        {
            if (function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                if (resident->id(name))
                {
                    foundResident = 1;
                }
                Spawned += ({ resident });
            }
        }
        ExpectTrue(foundResident, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void TirwenBranchesFromTheMeasuredKingsRoad()
{
    object road = load_object(
        "/areas/eledhel/south-rural-route-05/20x2.c");
    object entry = load_object("/areas/eledhel/tirwen/3x1.c");
    object farmDoor = load_object("/areas/eledhel/tirwen/4x2.c");
    object interiorEntry =
        load_object("/areas/eledhel/tirwen/farmhouse/0x1.c");
    object region = load_object("/areas/eledhel/tirwen/region.c");

    ExpectEq("/areas/eledhel/tirwen/3x1.c",
        road->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/south-rural-route-05/20x2.c",
        entry->getExitDirections()["default"]["south"]);
    ExpectEq("village road T-north", road->decoratorType(0));
    ExpectEq("/areas/eledhel/tirwen/4x1.c",
        farmDoor->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/tirwen/farmhouse/0x1.c",
        farmDoor->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/tirwen/4x2.c",
        interiorEntry->getExitDirections()["default"]["west"]);
    ExpectEq(7, region->xDimension());
    ExpectEq(5, region->yDimension());
}

/////////////////////////////////////////////////////////////////////////////
void TirwenResidentsAppearAtTheirWorksites()
{
    mapping residents = ([
        "/areas/eledhel/tirwen/farmhouse/0x0.c": "Rilwen",
        "/areas/eledhel/tirwen/6x1.c": "Edran"
    ]);

    foreach (string path, string name in residents)
    {
        object room = clone_object(path);
        Harvested += ({ room });
        int foundResident = 0;
        move_object(Player, room);
        foreach (object resident in all_inventory(room))
        {
            if (resident != Player &&
                function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                if (resident->id(name))
                {
                    foundResident = 1;
                }
                Spawned += ({ resident });
            }
        }
        ExpectTrue(foundResident, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void DhorlenBranchesFromTheMeasuredRoadAndCrossesTheRiver()
{
    object road = load_object(
        "/areas/eledhel/south-rural-route-07/22x2.c");
    object entry = load_object("/areas/eledhel/dhorlen/3x1.c");
    object yard = load_object("/areas/eledhel/dhorlen/2x2.c");
    object millEntry = load_object("/areas/eledhel/dhorlen/mill/0x1.c");
    object region = load_object("/areas/eledhel/dhorlen/region.c");

    ExpectEq("/areas/eledhel/dhorlen/3x1.c",
        road->getExitDirections()["default"]["south"]);
    ExpectEq("village road T-south", road->decoratorType(0));
    ExpectEq("/areas/eledhel/south-rural-route-07/22x2.c",
        entry->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/dhorlen/mill/0x1.c",
        yard->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/dhorlen/2x2.c",
        millEntry->getExitDirections()["default"]["south"]);
    ExpectTrue(shortestRoomPathInRegion(region,
        "/areas/eledhel/dhorlen/3x1.c",
        "/areas/eledhel/dhorlen/3x3.c") >= 2);
}

/////////////////////////////////////////////////////////////////////////////
void DhorlenMillerAppearsAtTheWaterMill()
{
    object room = clone_object("/areas/eledhel/dhorlen/mill/0x0.c");
    Harvested += ({ room });
    move_object(Player, room);
    int foundResident = 0;

    foreach (object resident in all_inventory(room))
    {
        if (resident != Player &&
            function_exists("isRealizationOfNpc", resident) &&
            resident->isRealizationOfNpc())
        {
            if (resident->id("Nereth"))
            {
                foundResident = 1;
            }
            Spawned += ({ resident });
        }
    }
    ExpectTrue(foundResident);
}

/////////////////////////////////////////////////////////////////////////////
void HadrathWatchlandsContainTwoHundredConnectedRooms()
{
    object region = load_object(
        "/areas/eledhel/hadrath/watchlands/region.c");
    object road = load_object(
        "/areas/eledhel/south-rural-route-08/18x2.c");
    int placedRooms = 0;

    for (int x = 0; x < region->xDimension(); x++)
    {
        for (int y = 0; y < region->yDimension(); y++)
        {
            mapping cell = region->coordinateToMapping(x, y);
            if (mappingp(cell) && cell["is placed"])
            {
                placedRooms++;
            }
        }
    }

    ExpectEq(200, placedRooms);
    ExpectEq("/areas/eledhel/hadrath/watchlands/0x0.c",
        road->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/south-rural-route-08/18x2.c",
        load_object("/areas/eledhel/hadrath/watchlands/0x0.c")->
            getExitDirections()["default"]["north"]);
    ExpectTrue(shortestRoomPathInRegion(region,
        "/areas/eledhel/hadrath/watchlands/0x0.c",
        "/areas/eledhel/hadrath/watchlands/19x9.c") >= 20);
}

/////////////////////////////////////////////////////////////////////////////
void HadrathResidentsAppearAtTheirWorksites()
{
    mapping residents = ([
        "/areas/eledhel/hadrath/watchlands/6x1.c": "Maereth",
        "/areas/eledhel/hadrath/watchlands/16x8.c": "Daerwen",
        "/areas/eledhel/hadrath/keep-interior/2x1.c": "Thalen"
    ]);

    foreach (string path, string name in residents)
    {
        object room = clone_object(path);
        Harvested += ({ room });
        move_object(Player, room);
        int foundResident = 0;
        foreach (object resident in all_inventory(room))
        {
            if (resident != Player &&
                function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                ExpectTrue(resident->id(name), path);
                foundResident++;
                Spawned += ({ resident });
            }
        }
        ExpectEq(1, foundResident, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void AladainUsesTheKeepTemplateWithoutBeingPlayerClaimable()
{
    object service = getService("domain");
    mapping holding = service->getAuthoredHolding("house aladain");

    ExpectTrue(mappingp(holding));
    ExpectEq("house-aladain", holding["id"]);
    ExpectEq("House Aladain", holding["name"]);
    ExpectEq("Lord and Lady Aladain", holding["owner"]);
    ExpectEq("keep", holding["type"]);
    ExpectFalse(service->getPlayerHolding(Player, "house aladain"));

    mapping domain = service->getPlayerDomain(
        Player, "house aladain", holding["type"]);
    ExpectEq("keep", domain["type"]);
    ExpectTrue(sizeof(domain["layout"]) > 0);
}

/////////////////////////////////////////////////////////////////////////////
void HadrathUsesTheKeepTemplateWithoutBeingPlayerClaimable()
{
    object service = getService("domain");
    mapping holding = service->getAuthoredHolding("house hadrath");

    ExpectTrue(mappingp(holding));
    ExpectEq("house-hadrath", holding["id"]);
    ExpectEq("House Hadrath", holding["name"]);
    ExpectEq("Eledhel", holding["allegiance"]);
    ExpectEq("/areas/eledhel/hadrath/grounds/0x2.c",
        holding["entry point"]);
    ExpectEq("keep", holding["type"]);
    ExpectFalse(service->getPlayerHolding(Player, "house hadrath"));

    mapping domain = service->getPlayerDomain(
        Player, "house hadrath", holding["type"]);
    ExpectEq("keep", domain["type"]);
    ExpectTrue(sizeof(domain["layout"]) > 0);
}

/////////////////////////////////////////////////////////////////////////////
void AladainEstateConnectsTheRoadVillageAndKeep()
{
    object road = load_object("/areas/eledhel/central-rural/21x3.c");
    object lane = load_object(
        "/areas/eledhel/estates/aladain/grounds/0x2.c");
    object yard = load_object(
        "/areas/eledhel/estates/aladain/grounds/3x4.c");
    object keep = load_object(
        "/areas/eledhel/estates/aladain/keep-interior/2x0.c");
    object millYard = load_object(
        "/areas/eledhel/estates/aladain/grounds/3x2.c");
    object mill = load_object(
        "/areas/eledhel/estates/aladain/mill/0x0.c");

    ExpectEq("/areas/eledhel/estates/aladain/grounds/0x2.c",
        road->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/central-rural/21x3.c",
        lane->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/estates/aladain/keep-interior/2x0.c",
        yard->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/estates/aladain/grounds/3x4.c",
        keep->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/estates/aladain/mill/0x0.c",
        millYard->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/estates/aladain/grounds/3x2.c",
        mill->getExitDirections()["default"]["west"]);
}

/////////////////////////////////////////////////////////////////////////////
void AladainResidentsAppearAtTheirWorksites()
{
    string *locations = ({
        "/areas/eledhel/estates/aladain/grounds/2x3.c",
        "/areas/eledhel/estates/aladain/mill/0x0.c",
        "/areas/eledhel/estates/aladain/stable/0x0.c",
        "/areas/eledhel/estates/aladain/keep-interior/1x1.c"
    });

    foreach(string path in locations)
    {
        object room = load_object(path);
        move_object(Player, room);

        int residentCount = 0;
        foreach(object item in all_inventory(room))
        {
            if ((item != Player) &&
                (member(inherit_list(item), "/lib/realizations/npc.c") >= 0))
            {
                residentCount++;
                Harvested += ({ item });
            }
        }
        ExpectEq(1, residentCount, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ArgalenKeepHasAccessibleGatedEntry()
{
    object exterior = load_object(
        "/areas/argalen-keep/surrounding/12x8.c");
    object gatehouse = load_object(
        "/areas/argalen-keep/keep-interior/5x0.c");
    object region = load_object(
        "/areas/argalen-keep/keep-interior/region.c");

    ExpectEq("/areas/argalen-keep/keep-interior/5x0.c",
        exterior->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/argalen-keep/surrounding/12x8.c",
        gatehouse->getExitDirections()["default"]["south"]);
    ExpectTrue(exterior->isEnvironmentalElement("keep gate"));
    ExpectTrue(gatehouse->isEnvironmentalElement("keep gate"));
    ExpectEq("/areas/argalen-keep/surrounding/12x8.c",
        region->entryPoint());
    ExpectEq("south", region->entryDirection());
}

/////////////////////////////////////////////////////////////////////////////
void ArgalenFarmsteadHasATenantAndWorkingFeatures()
{
    object farmstead = clone_object(
        "/areas/argalen-keep/surrounding/10x3.c");
    move_object(Player, farmstead);

    int residentCount = 0;
    foreach (object resident in all_inventory(farmstead))
    {
        if (resident != Player &&
            function_exists("isRealizationOfNpc", resident) &&
            resident->isRealizationOfNpc())
        {
            ExpectTrue(resident->id("Harlan Reed"));
            residentCount++;
            Spawned += ({ resident });
        }
    }
    ExpectEq(1, residentCount, "the farmstead has one named resident");

    ExpectTrue(farmstead->isEnvironmentalElement("field drain"));
    ExpectTrue(farmstead->isEnvironmentalElement("wooden fence"));
}

/////////////////////////////////////////////////////////////////////////////
void ArgalenVillageResidentsHaveWorkingConversations()
{
    string *residents = ({
        "/areas/argalen-keep/surrounding/characters/aldric/aldric.c",
        "/areas/argalen-keep/surrounding/characters/branna/branna.c",
        "/areas/argalen-keep/surrounding/characters/marta/marta.c",
        "/areas/argalen-keep/surrounding/characters/osric/osric.c"
    });

    foreach (string path in residents)
    {
        object resident = clone_object(path);
        ExpectTrue(resident->isRealizationOfNpc(), path);
        Spawned += ({ resident });
    }
}

/////////////////////////////////////////////////////////////////////////////
void ArgalenPatrolWoodsConnectsTheOpeningRoute()
{
    object region = load_object(
        "/areas/argalen-keep/patrol-woods/region.c");
    object village = load_object(
        "/areas/argalen-keep/surrounding/8x4.c");
    object woodsEast = load_object(
        "/areas/argalen-keep/patrol-woods/24x4.c");
    object tolDhurath = load_object("/areas/tol-dhurath/entry/17x0.c");
    object woodsWest = load_object(
        "/areas/argalen-keep/patrol-woods/0x4.c");
    int registeredRooms = 0;

    ExpectEq(25, region->xDimension());
    ExpectEq(10, region->yDimension());
    ExpectEq(3, region->regionLevel());
    ExpectEq("/areas/argalen-keep/patrol-woods/24x4.c",
        village->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/argalen-keep/surrounding/8x4.c",
        woodsEast->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/argalen-keep/patrol-woods/0x4.c",
        tolDhurath->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/tol-dhurath/entry/17x0.c",
        woodsWest->getExitDirections()["default"]["west"]);

    for (int x = 0; x < region->xDimension(); x++)
    {
        mapping cell = region->coordinateToMapping(x, 4);
        if (mappingp(cell) && cell["is placed"])
        {
            registeredRooms++;
            object room = cell["environment"];
            mapping exits = room->getExitDirections()["default"];
            ExpectEq(-1, member(inherit_list(room),
                "/lib/environment/generatedEnvironment.c"), cell["name"]);
            ExpectTrue(member(exits, "east"), cell["name"]);
            ExpectTrue(member(exits, "west"), cell["name"]);
            if (x < 24)
            {
                ExpectEq(sprintf(
                    "/areas/argalen-keep/patrol-woods/%dx4.c", x + 1),
                    exits["east"], cell["name"]);
            }
            if (x > 0)
            {
                ExpectEq(sprintf(
                    "/areas/argalen-keep/patrol-woods/%dx4.c", x - 1),
                    exits["west"], cell["name"]);
            }
        }
    }
    ExpectEq(25, registeredRooms);

    ExpectEq("/areas/argalen-keep/patrol-woods/12x3.c",
        region->getEnvironment("12x4")->getExitDirections()
            ["default"]["north"]);
    ExpectEq("/areas/argalen-keep/patrol-woods/18x3.c",
        region->getEnvironment("18x4")->getExitDirections()
            ["default"]["north"]);
    ExpectTrue(region->getEnvironment("7x4")->
        isEnvironmentalElement("blackberry bramble"));
    ExpectTrue(region->getEnvironment("14x4")->
        isEnvironmentalElement("raspberry canes"));
    ExpectTrue(region->getEnvironment("12x3")->
        isEnvironmentalElement("hunter's lean-to"));
    ExpectTrue(region->getEnvironment("18x4")->
        isEnvironmentalElement("warning sign"));
}

/////////////////////////////////////////////////////////////////////////////
void ArgalenPatrolCoastConnectsTheSouthernRoad()
{
    object region = load_object(
        "/areas/argalen-keep/patrol-coast/region.c");
    object village = load_object(
        "/areas/argalen-keep/surrounding/12x0.c");
    object entry = region->getEnvironment("12x0");
    object easternEdge = region->getEnvironment("24x4");
    int registeredRooms = 0;

    ExpectEq(25, region->xDimension());
    ExpectEq(10, region->yDimension());
    ExpectEq("rocky shoreline", region->regionType());
    ExpectEq(2, region->regionLevel());
    ExpectEq("/areas/argalen-keep/patrol-coast/12x0.c",
        village->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/argalen-keep/surrounding/12x0.c",
        entry->getExitDirections()["default"]["north"]);

    for (int y = 0; y < region->yDimension(); y++)
    {
        for (int x = 0; x < region->xDimension(); x++)
        {
            mapping cell = region->coordinateToMapping(x, y);
            if (mappingp(cell) && cell["is placed"])
            {
                registeredRooms++;
                ExpectEq(-1, member(inherit_list(cell["environment"]),
                    "/lib/environment/generatedEnvironment.c"),
                    cell["name"]);
            }
        }
    }
    ExpectEq(28, registeredRooms);

    for (int y = 0; y < 4; y++)
    {
        ExpectEq(sprintf(
            "/areas/argalen-keep/patrol-coast/12x%d.c", y + 1),
            region->getEnvironment(sprintf("12x%d", y))
                ->getExitDirections()["default"]["south"]);
    }
    for (int x = 12; x < 24; x++)
    {
        ExpectEq(sprintf(
            "/areas/argalen-keep/patrol-coast/%dx4.c", x + 1),
            region->getEnvironment(sprintf("%dx4", x))
                ->getExitDirections()["default"]["east"]);
    }
    ExpectFalse(member(easternEdge->getExitDirections()["default"],
        "east"));
    ExpectEq("/areas/argalen-keep/patrol-coast/10x5.c",
        region->getEnvironment("10x4")->getExitDirections()
            ["default"]["south"]);
    ExpectEq("/areas/argalen-keep/patrol-coast/17x5.c",
        region->getEnvironment("17x4")->getExitDirections()
            ["default"]["south"]);
    ExpectEq("/areas/argalen-keep/patrol-coast/21x5.c",
        region->getEnvironment("21x4")->getExitDirections()
            ["default"]["south"]);
    ExpectTrue(region->getEnvironment("10x2")->
        isEnvironmentalElement("blackberry bramble"));
    ExpectTrue(region->getEnvironment("11x2")->
        isEnvironmentalElement("common grain strips"));
    ExpectTrue(region->getEnvironment("8x4")->
        isEnvironmentalElement("fishing hut"));
    ExpectTrue(region->getEnvironment("21x6")->
        isEnvironmentalElement("lighthouse"));
}

/////////////////////////////////////////////////////////////////////////////
void BuildingInteriorsHaveReciprocalDoorsAndLighting()
{
    foreach (string path in ({
        "/areas/eledhel/central-rural/23x2.c",
        "/areas/eledhel/central-rural/20x4.c",
        "/areas/eledhel/central-rural/20x5.c" }))
    {
        object room = load_object(path);
        ExpectTrue(room->isEnvironmentalElement("plank door"), path);
        ExpectTrue(room->isEnvironmentalElement("oil lamp"), path);
        foreach (string direction, string destination in
            room->getExitDirections()["default"])
        {
            ExpectTrue(load_object(destination)->
                isEnvironmentalElement("plank door"), destination);
        }
    }
    object cellar = load_object("/areas/eledhel/central-rural/23x8.c");
    ExpectTrue(cellar->isEnvironmentalElement("plank door"));
    ExpectFalse(cellar->isEnvironmentalElement("oil lamp"));
}

/////////////////////////////////////////////////////////////////////////////
void ArgalenKeepLibraryContainsEledhelHistory()
{
    string *paths = ({
        "/areas/argalen-keep/keep-interior/4x6.c",
        "/areas/argalen-keep/keep-interior/6x6.c"
    });
    string *titles = ({
        "The Chronicle of Eledhel: Being an Account of Its Founding "
            "and Early Years",
        "The Founding of Eledhel: A Song of Ruin and Renewal"
    });

    for (int i = 0; i < sizeof(paths); i++)
    {
        object room = load_object(paths[i]);
        int foundBook = 0;

        foreach (object item in all_inventory(room))
        {
            if (item->query("title") == titles[i])
            {
                foundBook = 1;
                ExpectTrue(item->numChapters() > 0, paths[i]);
            }
        }
        ExpectTrue(foundBook, paths[i]);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ArgalenVillageShopsHaveReciprocalPlankDoors()
{
    object marketStreet = load_object(
        "/areas/argalen-keep/surrounding/13x5.c");
    object market = load_object(
        "/areas/argalen-keep/surrounding/market/0x0.c");
    object grocer = load_object(
        "/areas/argalen-keep/surrounding/13x6.c");

    ExpectEq("/areas/argalen-keep/surrounding/market/0x0.c",
        marketStreet->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/argalen-keep/surrounding/13x5.c",
        market->getExitDirections()["default"]["west"]);
    ExpectTrue(marketStreet->isEnvironmentalElement("plank door"));
    ExpectTrue(market->isEnvironmentalElement("plank door"));

    ExpectEq("/areas/argalen-keep/surrounding/13x6.c",
        marketStreet->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/argalen-keep/surrounding/13x5.c",
        grocer->getExitDirections()["default"]["west"]);
    ExpectTrue(grocer->isEnvironmentalElement("plank door"));
}

/////////////////////////////////////////////////////////////////////////////
void CentralCityUnbuiltInteriorsRemainClosedFacades()
{
    ExpectEq("/areas/eledhel/central-city/leather-merchant/0x0.c",
        load_object("/areas/eledhel/central-city/14x0.c")->
            getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/old-city-tailor/0x0.c",
        load_object("/areas/eledhel/central-city/14x1.c")->
            getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/palace/0x2.c",
        load_object("/areas/eledhel/central-city/14x5.c")->
            getExitDirections()["default"]["east"]);
    ExpectFalse(member(load_object(
        "/areas/eledhel/central-city/17x0.c")->
        getExitDirections()["default"], "east"));
    ExpectFalse(member(load_object(
        "/areas/eledhel/central-city/17x0.c")->
        getExitDirections()["default"], "west"));
    ExpectFalse(member(load_object(
        "/areas/eledhel/central-city/17x1.c")->
        getExitDirections()["default"], "east"));
    ExpectFalse(member(load_object(
        "/areas/eledhel/central-city/17x1.c")->
        getExitDirections()["default"], "west"));
    ExpectFalse(member(load_object(
        "/areas/eledhel/central-city/20x0.c")->
        getExitDirections()["default"], "west"));
    ExpectFalse(member(load_object(
        "/areas/eledhel/central-city/20x0.c")->
        getExitDirections()["default"], "east"));
    ExpectFalse(member(load_object(
        "/areas/eledhel/central-city/20x1.c")->
        getExitDirections()["default"], "west"));
    ExpectFalse(member(load_object(
        "/areas/eledhel/central-city/20x1.c")->
        getExitDirections()["default"], "east"));
    ExpectFalse(member(load_object(
        "/areas/eledhel/central-city/20x2.c")->
        getExitDirections()["default"], "east"));
}

/////////////////////////////////////////////////////////////////////////////
void CapitalNorthboundRouteIsBidirectional()
{
    object oldCity = load_object(
        "/areas/eledhel/central-city/12x9.c");
    object northCity = load_object(
        "/areas/eledhel/northern-city/12x0.c");

    ExpectEq("/areas/eledhel/northern-city/12x0.c",
        oldCity->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/central-city/12x9.c",
        northCity->getExitDirections()["default"]["south"]);
}

/////////////////////////////////////////////////////////////////////////////
void NorthernCityThroughRouteIsBidirectional()
{
    string **asciiIcon = getService("region")->getMapIcon(Region,
        "north-south road", "none", "ascii");
    string **unicodeIcon = getService("region")->getMapIcon(Region,
        "north-south road", "none", "unicode");
    string asciiRendered = "";
    string unicodeRendered = "";

    foreach (string *row in asciiIcon)
    {
        asciiRendered += implode(row, "");
    }
    foreach (string *row in unicodeIcon)
    {
        unicodeRendered += implode(row, "");
    }
    ExpectTrue(asciiRendered != "         ");
    ExpectTrue(unicodeRendered != "         ");

    for (int y = 0; y < 10; y++)
    {
        string path = sprintf("/areas/eledhel/northern-city/12x%d.c", y);
        object room = load_object(path);
        mapping exits = room->getExitDirections()["default"];

        ExpectEq(y == 6 ? "road intersection" : "north-south road",
            room->decoratorType(0));
        ExpectTrue(room->isEnvironmentalElement("cobblestone road"));
        if (y == 6)
        {
            ExpectEq("/areas/eledhel/northern-city/13x6.c", exits["east"]);
            ExpectEq("/areas/eledhel/northern-city/11x6.c", exits["west"]);
            ExpectEq("/areas/eledhel/northern-city/12x6.c",
                load_object("/areas/eledhel/northern-city/13x6.c")->
                    getExitDirections()["default"]["west"]);
            ExpectEq("/areas/eledhel/northern-city/12x6.c",
                load_object("/areas/eledhel/northern-city/11x6.c")->
                    getExitDirections()["default"]["east"]);
        }
        else
        {
            ExpectFalse(member(exits, "east"));
            ExpectFalse(member(exits, "west"));
        }

        if (y < 9)
        {
            string northPath = sprintf(
                "/areas/eledhel/northern-city/12x%d.c", y + 1);
            object northRoom = load_object(northPath);

            ExpectEq(northPath, exits["north"]);
            ExpectEq(path,
                northRoom->getExitDirections()["default"]["south"]);
        }
    }

    ExpectEq("/areas/eledhel/central-city/12x9.c",
        load_object("/areas/eledhel/northern-city/12x0.c")->
            getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/north-road/2x0.c",
        load_object("/areas/eledhel/northern-city/12x9.c")->
            getExitDirections()["default"]["north"]);
}

/////////////////////////////////////////////////////////////////////////////
void NorthernCityArenaDistrictConnectsToTheAvenue()
{
    for (int x = 3; x < 15; x++)
    {
        string path = sprintf("/areas/eledhel/northern-city/%dx6.c", x);
        string eastPath = sprintf("/areas/eledhel/northern-city/%dx6.c",
            x + 1);
        object room = load_object(path);
        object eastRoom = load_object(eastPath);

        ExpectEq(eastPath, room->getExitDirections()["default"]["east"]);
        ExpectEq(path, eastRoom->getExitDirections()["default"]["west"]);
    }

    object crossroads = load_object(
        "/areas/eledhel/northern-city/5x6.c");
    object park = load_object("/areas/eledhel/northern-city/5x7.c");
    object phaedraEntry = load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x4.c");
    object prisonEntry = load_object(
        "/areas/eledhel/northern-city/prison/0x2.c");
    object arenaEntry = load_object(
        "/areas/eledhel/northern-city/arena/4x2.c");

    ExpectEq("/areas/eledhel/northern-city/5x7.c",
        crossroads->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/northern-city/phaedra-headquarters/2x4.c",
        crossroads->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/northern-city/5x6.c",
        phaedraEntry->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/northern-city/prison/0x2.c",
        park->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/northern-city/arena/4x2.c",
        park->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/northern-city/5x7.c",
        prisonEntry->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/northern-city/5x7.c",
        arenaEntry->getExitDirections()["default"]["west"]);
}

/////////////////////////////////////////////////////////////////////////////
void NorthernCityPhaedraAndPrisonResidentsAppearAtTheirPosts()
{
    mapping residents = ([
        "/areas/eledhel/northern-city/phaedra-headquarters/3x2.c":
            "Sergeant Talan",
        "/areas/eledhel/northern-city/prison/2x3.c":"Oreth"
    ]);

    foreach (string path, string name in residents)
    {
        object room = clone_object(path);
        int foundResident = 0;
        Harvested += ({ room });
        move_object(Player, room);

        foreach (object resident in all_inventory(room))
        {
            if (function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                if (resident->id(name))
                {
                    foundResident = 1;
                }
                Spawned += ({ resident });
            }
        }
        ExpectTrue(foundResident, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void TolDhurathEntryRouteIsReciprocal()
{
    object entry = load_object(
        "/areas/tol-dhurath/entry/17x0.c");
    object trail = load_object(
        "/areas/tol-dhurath/entry/17x1.c");

    ExpectEq("/areas/tol-dhurath/entry/17x1.c",
        entry->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/tol-dhurath/entry/17x0.c",
        trail->getExitDirections()["default"]["south"]);
}

/////////////////////////////////////////////////////////////////////////////
void ArgalenPatrolWoodsConnectsDirectlyToForestOne()
{
    object woods = load_object(
        "/areas/argalen-keep/patrol-woods/0x4.c");
    object forest = load_object(
        "/areas/tol-dhurath/forest-1/24x5.c");

    ExpectEq("/areas/tol-dhurath/forest-1/24x5.c",
        woods->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/argalen-keep/patrol-woods/0x4.c",
        forest->getExitDirections()["default"]["south"]);
    ExpectEq("forest trail T-south", woods->decoratorType(0));
    ExpectEq("forest trail T-east", forest->decoratorType(0));
}

/////////////////////////////////////////////////////////////////////////////
protected void validateTolDhurathRouteDecorators(mapping routeDecorators,
    object region)
{
    foreach (string path, string decorator in routeDecorators)
    {
        object room = load_object(path);
        ExpectEq(-1, member(inherit_list(room),
            "/lib/environment/generatedEnvironment.c"), path);
        ExpectEq(decorator, room->decoratorType(0), path);

        string **icon = getService("region")->getMapIcon(
            region, decorator, "none", "ascii");
        string rendered = "";
        foreach (string *row in icon)
        {
            rendered += implode(row, "");
        }
        ExpectTrue(rendered != "         ", decorator);
    }
}

void TolDhurathEntryAndFirstForestRegionsHaveBoundedLevels()
{
    object entryRegion = clone_object(
        "/areas/tol-dhurath/entry/region.c");
    object forestRegion = clone_object(
        "/areas/tol-dhurath/forest-1/region.c");

    ExpectEq(3, entryRegion->regionLevel());
    ExpectEq(4, forestRegion->regionLevel());

    validateTolDhurathRouteDecorators(([
        "/areas/tol-dhurath/entry/17x0.c":
            "forest trail north-east",
        "/areas/tol-dhurath/entry/17x1.c":
            "forest trail T-south",
        "/areas/tol-dhurath/forest-1/17x2.c":
            "forest trail T-east",
        "/areas/tol-dhurath/forest-1/17x3.c":
            "forest trail north-south",
        "/areas/tol-dhurath/entry/7x9.c":
            "forest trail T-east",
        "/areas/tol-dhurath/forest-1/7x0.c":
            "forest trail north-south",
        "/areas/tol-dhurath/forest-1/0x6.c":
            "forest trail south-west"
    ]), forestRegion);

    destruct(entryRegion);
    destruct(forestRegion);
}

void TolDhurathLaterForestAndTempleRegionsHaveBoundedLevels()
{
    object secondForestRegion = clone_object(
        "/areas/tol-dhurath/forest-2/region.c");
    object thirdForestRegion = clone_object(
        "/areas/tol-dhurath/forest-3/region.c");
    object fourthForestRegion = clone_object(
        "/areas/tol-dhurath/forest-4/region.c");
    object fifthForestRegion = clone_object(
        "/areas/tol-dhurath/forest-5/region.c");
    object templeRegion = clone_object(
        "/areas/tol-dhurath/temple-exterior/region.c");

    ExpectEq(4, secondForestRegion->regionLevel());
    ExpectEq(5, thirdForestRegion->regionLevel());
    ExpectEq(6, fourthForestRegion->regionLevel());
    ExpectEq(7, fifthForestRegion->regionLevel());
    ExpectEq(6, templeRegion->regionLevel());

    validateTolDhurathRouteDecorators(([
        "/areas/tol-dhurath/forest-2/24x6.c":
            "forest trail T-east",
        "/areas/tol-dhurath/forest-2/0x4.c":
            "forest trail east-west",
        "/areas/tol-dhurath/forest-3/24x4.c":
            "forest trail T-east",
        "/areas/tol-dhurath/forest-3/0x8.c":
            "forest trail east-west",
        "/areas/tol-dhurath/temple-exterior/24x8.c":
            "forest trail south-east"
    ]), secondForestRegion);

    destruct(secondForestRegion);
    destruct(thirdForestRegion);
    destruct(fourthForestRegion);
    destruct(fifthForestRegion);
    destruct(templeRegion);
}

/////////////////////////////////////////////////////////////////////////////
void TolDhurathTrailJunctionHasNoncombatPassersby()
{
    object trail = load_object("/areas/tol-dhurath/forest-1/17x2.c");
    move_object(Player, trail);

    object *npcs = ({});
    foreach (object encounter in all_inventory(trail))
    {
        if (objectp(encounter) &&
            function_exists("isRealizationOfNpc", encounter) &&
            encounter->isRealizationOfNpc())
        {
            npcs += ({ encounter });
        }
    }

    ExpectEq(1, sizeof(npcs));
    if (sizeof(npcs))
    {
        ExpectTrue(npcs[0]->id("hunter") ||
            npcs[0]->id("white-tail deer"));
        Spawned += npcs;
    }
}

/////////////////////////////////////////////////////////////////////////////
void SouthernCityMissingInteriorsRemainClosedFacades()
{
    mapping* entrances = ({
        (["room": "/areas/eledhel/southern-city/10x2.c",
            "direction": "south"]),
        (["room": "/areas/eledhel/southern-city/13x2.c",
            "direction": "south"]),
        (["room": "/areas/eledhel/southern-city/19x1.c",
            "direction": "east"]),
        (["room": "/areas/eledhel/southern-city/1x5.c",
            "direction": "west"]),
        (["room": "/areas/eledhel/southern-city/20x9.c",
            "direction": "west"]),
        (["room": "/areas/eledhel/southern-city/2x1.c",
            "direction": "west"]),
        (["room": "/areas/eledhel/southern-city/3x5.c",
            "direction": "north"]),
        (["room": "/areas/eledhel/southern-city/3x8.c",
            "direction": "south"]),
        (["room": "/areas/eledhel/southern-city/4x5.c",
            "direction": "north"]),
        (["room": "/areas/eledhel/southern-city/4x8.c",
            "direction": "south"]),
        (["room": "/areas/eledhel/southern-city/6x3.c",
            "direction": "east"]),
        (["room": "/areas/eledhel/southern-city/6x4.c",
            "direction": "east"]),
        (["room": "/areas/eledhel/southern-city/8x2.c",
            "direction": "north"]),
        (["room": "/areas/eledhel/southern-city/8x5.c",
            "direction": "south"]),
        (["room": "/areas/eledhel/southern-city/9x3.c",
            "direction": "west"])
    });

    foreach(mapping entrance in entrances)
    {
        object room = load_object(entrance["room"]);
        ExpectFalse(member(room->getExitDirections()["default"],
            entrance["direction"]), entrance["room"]);
    }

    ExpectEq("/areas/eledhel/southern-city/shipyard/0x0.c",
        load_object("/areas/eledhel/southern-city/21x7.c")->
            getExitDirections()["default"]["east"]);
}

/////////////////////////////////////////////////////////////////////////////
void SouthernCityWallRoadHasReciprocalExits()
{
    object wallRoad = load_object(
        "/areas/eledhel/southern-city/1x2.c");
    object wallGate = load_object(
        "/areas/eledhel/southern-city/2x2.c");

    ExpectEq("/areas/eledhel/southern-city/2x2.c",
        wallRoad->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/1x2.c",
        wallGate->getExitDirections()["default"]["west"]);
}

/////////////////////////////////////////////////////////////////////////////
void PublicRootsAreSeasonalFiniteAndSeparateBetweenRooms()
{
    object first = load_object("/areas/eledhel/central-rural/22x4.c");
    object second = load_object("/areas/eledhel/central-rural/23x7.c");
    object service = getService("environment");
    int originalDay = service->currentDay();
    service->setDay(20);
    move_object(Player, first);
    ExpectFalse(objectp(first->harvestResource("carrot", Player)));
    service->setDay(260);
    for (int i = 0; i < 4; i++)
    {
        object item = first->harvestResource("carrot", Player);
        ExpectTrue(objectp(item));
        Harvested += ({ item });
    }
    ExpectFalse(objectp(first->harvestResource("carrot", Player)));
    move_object(Player, second);
    object item = second->harvestResource("carrot", Player);
    ExpectTrue(objectp(item));
    Harvested += ({ item });
    service->setDay(originalDay);
}

/////////////////////////////////////////////////////////////////////////////
void ProvisionCountersHaveRealPricedProduce()
{
    foreach (string path in ({
        "/areas/eledhel/central-rural/23x6.c",
        "/areas/eledhel/central-rural/20x4.c" }))
    {
        object shop = load_object(path)->getShop();
        ExpectTrue(objectp(shop), path);
        mapping stock = shop->storeInventory();
        ExpectEq(5, sizeof(stock), path);
        foreach (string key, mapping item in stock)
        {
            ExpectTrue(item["value"] > 0, key);
            ExpectTrue(item["quantity"] > 0, key);
        }
    }

}

/////////////////////////////////////////////////////////////////////////////
void PerasStandAndGardenPathsMatchTheirExits()
{
    object stand = load_object("/areas/eledhel/central-rural/23x6.c");
    object gardenRoom = load_object("/areas/eledhel/central-rural/23x7.c");
    foreach (object room in ({ stand, gardenRoom }))
    {
        mapping snapshot = room->buildRoomSnapshot();
        mapping *paths = filter(snapshot["features"],
            (: $1["name"] == "path" :));
        string *pathLocations = ({});

        ExpectEq(1, sizeof(paths));
        if (sizeof(paths))
        {
            foreach (mapping location in paths[0]["locations"])
            {
                pathLocations += ({ location["description"] });
            }
        }

        foreach (string direction, string target in
            room->getExitDirections()["default"])
        {
            ExpectTrue(member(pathLocations, direction) > -1, target);
        }
    }

    mapping snapshot = stand->buildRoomSnapshot();
    mapping *gardens = filter(snapshot["features"],
        (: $1["name"] == "common kitchen garden" :));
    ExpectEq(1, sizeof(gardens));
    if (sizeof(gardens) && sizeof(gardens[0]["locations"]))
    {
        ExpectEq("northeast", gardens[0]["locations"][0]["description"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
void AuthoredWildlifeAndOutlawsUseTheirPlacedDifficulty()
{
    mapping levels = ([
        "/areas/eledhel/central-rural/21x7.c":2,
        "/areas/eledhel/central-rural/21x8.c":3,
        "/areas/eledhel/central-rural/21x9.c":5,
        "/areas/eledhel/central-rural/23x8.c":2,
        "/areas/eledhel/estates/aladain/grounds/3x1.c":2,
        "/areas/minlach/surrounding/0x3.c":2,
        "/areas/minlach/surrounding/0x5.c":3,
        "/areas/minlach/surrounding/4x3.c":3,
        "/areas/minlach/shore/0x3.c":3,
        "/areas/argalen-keep/patrol-woods/18x3.c":4,
        "/areas/argalen-keep/patrol-coast/17x5.c":3,
        "/areas/argalen-keep/patrol-coast/17x6.c":2,
        "/areas/eledhel/tirwen/0x1.c":3,
        "/areas/eledhel/tirwen/5x1.c":3,
        "/areas/eledhel/dhorlen/4x4.c":3,
        "/areas/eledhel/hadrath/watchlands/0x6.c":3,
        "/areas/eledhel/hadrath/watchlands/1x5.c":4,
        "/areas/eledhel/hadrath/watchlands/15x9.c":4
    ]);
    foreach (string path, int level in levels)
    {
        object room = load_object(path);
        move_object(Player, room);
        int count = 0;
        foreach (object item in all_inventory(room))
        {
            if (item != Player)
            {
                ExpectEq(level, item->effectiveLevel(), path);
                ExpectTrue(member(inherit_list(item),
                    "/lib/realizations/monster.c") >= 0, path);
                count++;
                Harvested += ({ item });
            }
        }
        ExpectTrue(count >= 1 && count <= 3, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void WestRuralEncounterPoolsUseOpeningDifficulty()
{
    object region = clone_object("/areas/eledhel/west-rural/region.c");
    string *locations = ({
        "12x5",
        "14x5",
        "15x5",
        "16x3",
        "16x8",
        "17x6",
        "19x3",
        "19x9",
        "20x5",
        "20x6",
        "21x1",
        "2x8",
        "4x6",
        "7x6",
        "8x4"
    });

    ExpectEq(3, region->regionLevel());
    foreach (string location in locations)
    {
        object room = region->getEnvironment(location);
        string path = sprintf("/areas/eledhel/west-rural/%s.c", location);
        move_object(Player, room);
        int count = 0;
        foreach (object encounter in all_inventory(room))
        {
            if (encounter != Player)
            {
                int level = encounter->effectiveLevel();
                ExpectTrue(level >= 1 && level <= 5,
                    sprintf("%s encounter %s has level %d",
                        path, encounter->Name(), level));
                ExpectTrue(member(inherit_list(encounter),
                    "/lib/realizations/monster.c") >= 0,
                    sprintf("%s encounter %s is a monster",
                        path, encounter->Name()));
                count++;
                Harvested += ({ encounter });
            }
        }
        ExpectTrue(count >= 1 && count <= 3,
            sprintf("%s has %d encounters", path, count));
    }
    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void WestRuralEntryTrailIsAuthoredAndDecorated()
{
    object region = load_object("/areas/eledhel/west-rural/region.c");
    mapping rooms = ([
        "/areas/eledhel/west-rural/0x0.c": "forest trail T-north",
        "/areas/eledhel/west-rural/0x1.c": "forest trail south-east",
        "/areas/eledhel/west-rural/1x1.c": "forest trail east-west",
        "/areas/eledhel/west-rural/2x1.c": "forest trail north-west",
        "/areas/eledhel/west-rural/2x2.c": "forest trail south-west",
        "/areas/eledhel/west-rural/1x2.c": "forest trail north-east",
        "/areas/eledhel/west-rural/1x3.c": "forest trail south-east",
        "/areas/eledhel/west-rural/2x3.c": "forest trail east-west"
    ]);
    mapping opposite = ([
        "north":"south",
        "south":"north",
        "east":"west",
        "west":"east"
    ]);
    object entry = load_object("/areas/eledhel/west-rural/0x0.c");

    ExpectEq("/areas/eledhel/central-rural/22x5.c",
        entry->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/west-rural/0x0.c",
        load_object("/areas/eledhel/central-rural/22x5.c")->
            getExitDirections()["default"]["west"]);

    foreach (string path, string decorator in rooms)
    {
        object room = load_object(path);
        ExpectEq(-1, member(inherit_list(room),
            "/lib/environment/generatedEnvironment.c"), path);
        ExpectEq(decorator, room->decoratorType(0), path);

        mapping snapshot = room->buildRoomSnapshot();
        mapping *paths = filter(snapshot["features"],
            (: $1["name"] == "path" :));
        ExpectEq(1, sizeof(paths), path);

        string *pathLocations = ({});
        if (sizeof(paths))
        {
            foreach (mapping location in paths[0]["locations"])
            {
                pathLocations += ({ location["description"] });
            }
        }

        foreach (string direction, string target in
            room->getExitDirections()["default"])
        {
            ExpectTrue(member(pathLocations, direction) > -1, target);
            if (member(rooms, target))
            {
                ExpectEq(path,
                    load_object(target)->getExitDirections()["default"]
                        [opposite[direction]], path);
            }
        }

        string **icon = getService("region")->getMapIcon(
            region, decorator, "none", "ascii");
        string rendered = "";
        foreach (string *row in icon)
        {
            rendered += implode(row, "");
        }
        ExpectTrue(rendered != "         ", decorator);
    }
}

/////////////////////////////////////////////////////////////////////////////
void WesternWildsConnectToTheCapitalForestTrail()
{
    object westGate = clone_object("/areas/eledhel/west-rural/0x0.c");
    object wildGate = clone_object(
        "/areas/eledhel/west-rural-two/0x0.c");
    object region = clone_object(
        "/areas/eledhel/west-rural-two/region.c");

    ExpectEq("/areas/eledhel/west-rural-two/0x0.c",
        westGate->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/west-rural/0x0.c",
        wildGate->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/west-rural-two/1x0.c",
        wildGate->getExitDirections()["default"]["east"]);
    ExpectEq(4, region->regionLevel());
    ExpectEq("forest trail T-north", westGate->decoratorType(0));
    ExpectTrue(wildGate->isEnvironmentalElement("milestone"));
    ExpectEq(-1, member(inherit_list(wildGate),
        "/lib/environment/generatedEnvironment.c"));

    destruct(westGate);
    destruct(wildGate);
    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void WesternWildsPondAndFoxDenFormAnExplorableStop()
{
    object pond = clone_object(
        "/areas/eledhel/west-rural-two/7x2.c");
    object entrance = clone_object(
        "/areas/eledhel/west-rural-two/7x3.c");
    object denMouth = clone_object(
        "/areas/eledhel/west-rural-two/fox-den/0x0.c");
    object denRegion = clone_object(
        "/areas/eledhel/west-rural-two/fox-den/region.c");
    mapping passages = ([
        "0x0": "cave south-east passage",
        "1x0": "cave south-west passage",
        "0x1": "cave north-east passage",
        "1x1": "cave north-west passage"
    ]);

    ExpectEq("/areas/eledhel/west-rural-two/7x3.c",
        pond->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/west-rural-two/7x2.c",
        entrance->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/west-rural-two/fox-den/0x0.c",
        entrance->getExitDirections()["default"]["down"]);
    ExpectEq("/areas/eledhel/west-rural-two/7x3.c",
        denMouth->getExitDirections()["default"]["up"]);
    ExpectEq(25, denRegion->xDimension() * denRegion->yDimension());
    ExpectTrue(entrance->isEnvironmentalElement("fox tracks"));
    ExpectTrue(pond->isEnvironmentalElement("pond"));
    ExpectEq(-1, member(inherit_list(pond),
        "/lib/environment/generatedEnvironment.c"));

    foreach (string cell, string decorator in passages)
    {
        string path = sprintf(
            "/areas/eledhel/west-rural-two/fox-den/%s.c", cell);
        object chamber = clone_object(path);
        ExpectEq(decorator, chamber->decoratorType(0), path);
        ExpectTrue(denRegion->coordinateToMapping(
            to_int(cell[0..0]), to_int(cell[2..2])), path);

        string **icon = getService("region")->getMapIcon(
            denRegion, decorator, "none", "ascii");
        string rendered = "";
        foreach (string *row in icon)
        {
            rendered += implode(row, "");
        }
        ExpectTrue(rendered != "         ", decorator);
        destruct(chamber);
    }

    object innerDen = clone_object(
        "/areas/eledhel/west-rural-two/fox-den/1x1.c");
    mapping innerExits = innerDen->getExitDirections()["default"];
    ExpectEq("/areas/eledhel/west-rural-two/fox-den/1x0.c",
        innerExits["north"]);
    ExpectEq("/areas/eledhel/west-rural-two/fox-den/0x1.c",
        innerExits["west"]);
    destruct(innerDen);

    move_object(Player, pond);
    int wildlife = 0;
    int hostile = 0;
    foreach (object encounter in all_inventory(pond))
    {
        if (encounter != Player &&
            function_exists("isRealizationOfNpc", encounter) &&
            encounter->isRealizationOfNpc())
        {
            wildlife++;
            ExpectTrue(encounter->id("beaver") ||
                encounter->id("otter") || encounter->id("muskrat"));
            Spawned += ({ encounter });
        }
        else if (encounter != Player &&
            function_exists("isRealizationOfMonster", encounter) &&
            encounter->isRealizationOfMonster())
        {
            hostile++;
            Spawned += ({ encounter });
        }
    }
    ExpectEq(1, wildlife);
    ExpectEq(0, hostile);

    destruct(pond);
    destruct(entrance);
    destruct(denMouth);
}

/////////////////////////////////////////////////////////////////////////////
void WesternWildsAuthoredPoolsUseTheRegionalLevel()
{
    object region = clone_object(
        "/areas/eledhel/west-rural-two/region.c");
    object room = region->getEnvironment("1x1");
    move_object(Player, room);

    int encounters = 0;
    foreach (object encounter in all_inventory(room))
    {
        if (encounter != Player)
        {
            ExpectTrue(function_exists("isRealizationOfMonster", encounter));
            int level = encounter->effectiveLevel();
            ExpectTrue(level >= 2 && level <= 6,
                sprintf("Western Wilds encounter level %d", level));
            encounters++;
            Spawned += ({ encounter });
        }
    }
    ExpectTrue(encounters >= 1 && encounters <= 3);
    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void WesternWildsRavineAndRidgeRoutesAreAuthored()
{
    object region = clone_object(
        "/areas/eledhel/west-rural-two/region.c");
    mapping cells = ([
        "10x0": "forest trail north-east",
        "10x1": "forest trail south",
        "10x2": "forest trail north-west",
        "10x3": "forest trail south",
        "21x1": "forest trail north-east",
        "21x2": "forest trail north-south",
        "21x3": "forest trail T-south",
        "22x1": "forest trail east-west",
        "22x3": "forest trail west"
    ]);

    ExpectEq(4, region->regionLevel());
    foreach (string cell, string decorator in cells)
    {
        object room = region->getEnvironment(cell);
        ExpectEq(decorator, room->decoratorType(0), cell);
        ExpectEq(-1, member(inherit_list(room),
            "/lib/environment/generatedEnvironment.c"), cell);

        string **icon = getService("region")->getMapIcon(
            region, decorator, "none", "ascii");
        string rendered = "";
        foreach (string *row in icon)
        {
            rendered += implode(row, "");
        }
        ExpectTrue(rendered != "         ", cell);
    }

    object brook = region->getEnvironment("10x0");
    object shelf = region->getEnvironment("10x1");
    object falls = region->getEnvironment("10x2");
    object fallsShelf = region->getEnvironment("10x3");
    ExpectEq("/areas/eledhel/west-rural-two/10x1.c",
        brook->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/west-rural-two/10x0.c",
        shelf->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/west-rural-two/10x3.c",
        falls->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/west-rural-two/10x2.c",
        fallsShelf->getExitDirections()["default"]["south"]);
    ExpectTrue(brook->isEnvironmentalElement("canyon brook"));
    ExpectTrue(falls->isEnvironmentalElement("ravine waterfall"));

    move_object(Player, shelf);
    object *deer = filter(all_inventory(shelf),
        (: objectp($1) && $1 != Player &&
            function_exists("isRealizationOfNpc", $1) &&
            $1->isRealizationOfNpc() && $1->id("white-tail deer") :));
    ExpectEq(1, sizeof(deer));
    Spawned += deer;

    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void WesternWildsEasternRavineRoutesAreAuthored()
{
    object region = clone_object(
        "/areas/eledhel/west-rural-two/region.c");
    mapping cells = ([
        "17x4": "forest trail north-west",
        "17x5": "forest trail south-east",
        "17x8": "forest trail east-west",
        "18x5": "forest trail east-west",
        "18x6": "forest trail north-east",
        "18x7": "forest trail north-south",
        "18x8": "forest trail T-west",
        "18x9": "forest trail south-east",
        "19x5": "forest trail north-west",
        "19x6": "forest trail T-south",
        "19x9": "forest trail east-west",
        "20x3": "forest trail north-east",
        "20x4": "forest trail south",
        "20x5": "forest trail north",
        "20x6": "forest trail south-west",
        "20x9": "forest trail east-west",
        "21x9": "forest trail east-west",
        "22x6": "forest trail north-east",
        "22x7": "forest trail north-south",
        "22x8": "forest trail north-south",
        "22x9": "forest trail south-west",
        "23x5": "forest trail north-east",
        "23x6": "forest trail south-west",
        "24x5": "forest trail south-west"
    ]);

    ExpectEq(24, sizeof(cells));
    foreach (string cell, string decorator in cells)
    {
        object room = region->getEnvironment(cell);
        ExpectEq(decorator, room->decoratorType(0), cell);
        ExpectEq(-1, member(inherit_list(room),
            "/lib/environment/generatedEnvironment.c"), cell);

        string **icon = getService("region")->getMapIcon(
            region, decorator, "none", "ascii");
        string rendered = "";
        foreach (string *row in icon)
        {
            rendered += implode(row, "");
        }
        ExpectTrue(rendered != "         ", cell);
    }

    object fordApproach = region->getEnvironment("19x5");
    object ford = region->getEnvironment("19x6");
    object farTrack = region->getEnvironment("24x5");
    ExpectEq("/areas/eledhel/west-rural-two/19x6.c",
        fordApproach->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/west-rural-two/19x5.c",
        ford->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/west-rural-two/24x5.c",
        region->getEnvironment("23x5")
            ->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/west-rural-two/23x5.c",
        farTrack->getExitDirections()["default"]["west"]);
    ExpectTrue(region->getEnvironment("22x8")->
        isEnvironmentalElement("waterfall"));

    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void WesternWildsRemainingForestNetworkIsAuthoredAndMapped()
{
    object region = clone_object(
        "/areas/eledhel/west-rural-two/region.c");
    mapping cells = ([
        "0x3": "forest trail south-east",
        "1x3": "forest trail north-west",
        "1x4": "forest trail north-south",
        "1x5": "forest trail north-south",
        "1x6": "forest trail south",
        "2x0": "forest trail north-east",
        "2x1": "forest trail north-south",
        "2x2": "forest trail south-west",
        "3x0": "forest trail north-west",
        "3x1": "forest trail south-east",
        "4x1": "forest trail east-west",
        "5x1": "forest trail north-west",
        "5x2": "forest trail south-east",
        "6x2": "forest trail north-west",
        "6x3": "forest trail south-east",
        "8x2": "forest trail east-west",
        "9x2": "forest trail east-west",
        "3x5": "forest trail north-east",
        "3x6": "forest trail south",
        "3x7": "forest trail north-east",
        "3x8": "forest trail south",
        "4x5": "forest trail north-west",
        "4x6": "forest trail north-south",
        "4x7": "forest trail T-south",
        "5x5": "forest trail north-east",
        "5x6": "forest trail south-east",
        "5x7": "forest trail east-west",
        "5x9": "forest trail east",
        "6x5": "forest trail west",
        "6x6": "forest trail north-west",
        "6x7": "forest trail T-south",
        "6x9": "forest trail east-west",
        "7x4": "forest trail north-south",
        "7x5": "forest trail T-east",
        "7x6": "forest trail north-south",
        "7x7": "forest trail T-south",
        "7x9": "forest trail east-west",
        "8x5": "forest trail east-west",
        "8x7": "forest trail north-west",
        "8x8": "forest trail south-east",
        "8x9": "forest trail east-west",
        "9x5": "forest trail T-north",
        "9x6": "forest trail south",
        "9x8": "forest trail east-west",
        "9x9": "forest trail east-west",
        "10x4": "forest trail east",
        "10x5": "forest trail west",
        "10x8": "forest trail north-west",
        "10x9": "forest trail T-south",
        "11x0": "forest trail east-west",
        "12x0": "forest trail east-west",
        "13x0": "forest trail east-west",
        "14x0": "forest trail east-west",
        "15x0": "forest trail north-west",
        "15x1": "forest trail north-south",
        "15x2": "forest trail north-south",
        "15x3": "forest trail south-east",
        "16x3": "forest trail north-west",
        "16x4": "forest trail south-east"
    ]);

    ExpectEq(59, sizeof(cells));
    foreach (string cell, string decorator in cells)
    {
        object room = region->getEnvironment(cell);
        ExpectEq(decorator, room->decoratorType(0), cell);
        ExpectEq(-1, member(inherit_list(room),
            "/lib/environment/generatedEnvironment.c"), cell);

        string **icon = getService("region")->getMapIcon(
            region, decorator, "none", "ascii");
        string rendered = "";
        foreach (string *row in icon)
        {
            rendered += implode(row, "");
        }
        ExpectTrue(rendered != "         ", cell);
    }

    ExpectEq("/areas/eledhel/west-rural-two/1x3.c",
        region->getEnvironment("0x3")
            ->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/west-rural-two/15x1.c",
        region->getEnvironment("15x0")
            ->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/west-rural-two/17x4.c",
        region->getEnvironment("16x4")
            ->getExitDirections()["default"]["east"]);

    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void WesternWildsFarEasternRidgeBranchIsAuthored()
{
    object region = clone_object(
        "/areas/eledhel/west-rural-two/region.c");
    mapping cells = ([
        "23x0": "forest trail north-east",
        "23x1": "forest trail T-west",
        "23x2": "forest trail south-east",
        "24x0": "forest trail north-west",
        "24x1": "forest trail south",
        "24x2": "forest trail north-west",
        "24x3": "forest trail north-south",
        "24x4": "forest trail T-east"
    ]);

    ExpectEq(8, sizeof(cells));
    foreach (string cell, string decorator in cells)
    {
        object room = region->getEnvironment(cell);
        ExpectEq(decorator, room->decoratorType(0), cell);
        ExpectEq(-1, member(inherit_list(room),
            "/lib/environment/generatedEnvironment.c"), cell);

        string **icon = getService("region")->getMapIcon(
            region, decorator, "none", "ascii");
        string rendered = "";
        foreach (string *row in icon)
        {
            rendered += implode(row, "");
        }
        ExpectTrue(rendered != "         ", cell);
    }

    ExpectEq("/areas/eledhel/west-rural-two/24x0.c",
        region->getEnvironment("23x0")
            ->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/west-rural-two/24x1.c",
        region->getEnvironment("24x0")
            ->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/west-rural-two/24x4.c",
        region->getEnvironment("24x3")
            ->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/west-rural-two/24x5.c",
        region->getEnvironment("24x4")
            ->getExitDirections()["default"]["north"]);
    ExpectTrue(region->getEnvironment("23x2")->
        isEnvironmentalElement("canyon creek"));

    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void EvenholtEstateConnectsItsGroundsHouseholdAndCave()
{
    object wilds = clone_object(
        "/areas/eledhel/west-rural-two/region.c");
    object grounds = clone_object("/areas/evenholt/grounds/region.c");
    object manor = clone_object("/areas/evenholt/manor/region.c");
    object cellar = clone_object(
        "/areas/evenholt/manor-cellar/region.c");
    object caves = clone_object(
        "/areas/evenholt/limestone-caves/region.c");

    object westEdge = wilds->getEnvironment("24x4");
    object entry = grounds->getEnvironment("0x4");
    object yard = grounds->getEnvironment("20x4");
    object stableYard = grounds->getEnvironment("21x4");
    object hiddenClearing = grounds->getEnvironment("20x3");
    object camp = grounds->getEnvironment("20x0");
    object surfacePool = grounds->getEnvironment("24x2");
    object frontHall = manor->getEnvironment("0x1");
    object kitchen = manor->getEnvironment("2x1");
    object cellarEntry = cellar->getEnvironment("0x0");
    object caveEntry = caves->getEnvironment("0x0");
    object caveExit = caves->getEnvironment("4x0");
    object *yardResidents = all_inventory(yard);
    object *stableResidents = all_inventory(stableYard);
    object *kitchenResidents = all_inventory(kitchen);
    object *gardenResidents =
        all_inventory(grounds->getEnvironment("22x3"));
    object *campResidents = all_inventory(camp);

    ExpectEq("/areas/evenholt/grounds/0x4.c",
        westEdge->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/west-rural-two/24x4.c",
        entry->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/evenholt/manor/0x1.c",
        yard->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/evenholt/grounds/20x4.c",
        frontHall->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/evenholt/grounds/20x2.c",
        hiddenClearing->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/evenholt/limestone-caves/0x0.c",
        camp->getExitDirections()["default"]["down"]);
    ExpectEq("/areas/evenholt/grounds/20x0.c",
        caveEntry->getExitDirections()["default"]["up"]);
    ExpectEq("/areas/evenholt/grounds/24x2.c",
        caveExit->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/evenholt/limestone-caves/4x0.c",
        surfacePool->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/evenholt/manor/3x1.c",
        cellarEntry->getExitDirections()["default"]["up"]);

    ExpectEq(1, sizeof(yardResidents));
    ExpectTrue(yardResidents[0]->id("Aglaradan"));
    ExpectEq(2, sizeof(stableResidents));
    ExpectTrue(stableResidents[0]->id("Cyril") ||
        stableResidents[1]->id("Cyril"));
    ExpectTrue(stableResidents[0]->id("Hrothgil") ||
        stableResidents[1]->id("Hrothgil"));
    ExpectEq(1, sizeof(kitchenResidents));
    ExpectTrue(kitchenResidents[0]->id("Lydia"));
    ExpectEq(1, sizeof(gardenResidents));
    ExpectTrue(gardenResidents[0]->id("Mirael"));
    ExpectEq(1, sizeof(campResidents));
    ExpectTrue(campResidents[0]->id("Tinruth"));

    destruct(wilds);
    destruct(grounds);
    destruct(manor);
    destruct(cellar);
    destruct(caves);
}

/////////////////////////////////////////////////////////////////////////////
void WesternWildsWatershedLoopIsAuthoredAndMapped()
{
    object region = clone_object(
        "/areas/eledhel/west-rural-two/region.c");
    mapping cells = ([
        "11x4": "forest trail east-west",
        "12x4": "forest trail north-west",
        "12x5": "forest trail south-east",
        "13x5": "forest trail T-north",
        "13x6": "forest trail south-west",
        "14x5": "forest trail east-west",
        "15x5": "forest trail east-west",
        "16x5": "forest trail north-west",
        "16x6": "forest trail north-south",
        "16x7": "forest trail north-south",
        "16x8": "forest trail T-east",
        "16x9": "forest trail south-west",
        "11x6": "forest trail north-east",
        "12x6": "forest trail east-west",
        "11x7": "forest trail south-east",
        "12x7": "forest trail east-west",
        "11x8": "forest trail east-west",
        "11x9": "forest trail south-west",
        "12x8": "forest trail east-west",
        "13x7": "forest trail north-west",
        "13x8": "forest trail T-west",
        "13x9": "forest trail south-east",
        "14x9": "forest trail east-west",
        "15x9": "forest trail east-west"
    ]);

    ExpectEq(4, region->regionLevel());
    ExpectEq(24, sizeof(cells));
    foreach (string cell, string decorator in cells)
    {
        object room = region->getEnvironment(cell);
        ExpectEq(decorator, room->decoratorType(0), cell);
        ExpectEq(-1, member(inherit_list(room),
            "/lib/environment/generatedEnvironment.c"), cell);

        string **icon = getService("region")->getMapIcon(
            region, decorator, "none", "ascii");
        string rendered = "";
        foreach (string *row in icon)
        {
            rendered += implode(row, "");
        }
        ExpectTrue(rendered != "         ", cell);
    }

    ExpectEq("/areas/eledhel/west-rural-two/12x4.c",
        region->getEnvironment("11x4")->getExitDirections()
            ["default"]["east"]);
    ExpectEq("/areas/eledhel/west-rural-two/11x4.c",
        region->getEnvironment("12x4")->getExitDirections()
            ["default"]["west"]);
    ExpectEq("/areas/eledhel/west-rural-two/16x5.c",
        region->getEnvironment("16x6")->getExitDirections()
            ["default"]["south"]);
    ExpectTrue(region->getEnvironment("16x5")->
        isEnvironmentalElement("waterfall"));

    object shallowReach = region->getEnvironment("12x8");
    move_object(Player, shallowReach);
    object *wildlife = filter(all_inventory(shallowReach),
        (: objectp($1) && $1 != Player &&
            function_exists("isRealizationOfNpc", $1) &&
            $1->isRealizationOfNpc() &&
            ($1->id("otter") || $1->id("muskrat")) :));
    ExpectEq(1, sizeof(wildlife));
    Spawned += wildlife;

    destruct(region);
}

/////////////////////////////////////////////////////////////////////////////
void WestRuralEntryHasNoncombatWildlife()
{
    object trail = load_object("/areas/eledhel/west-rural/0x0.c");
    move_object(Player, trail);

    object *npcs = ({});
    int monsters = 0;
    foreach (object encounter in all_inventory(trail))
    {
        if (objectp(encounter) &&
            function_exists("isRealizationOfNpc", encounter) &&
            encounter->isRealizationOfNpc())
        {
            npcs += ({ encounter });
        }
        else if (objectp(encounter) &&
            function_exists("isRealizationOfMonster", encounter) &&
            encounter->isRealizationOfMonster())
        {
            monsters++;
        }
    }

    ExpectEq(1, sizeof(npcs));
    ExpectEq(0, monsters);
    if (sizeof(npcs))
    {
        ExpectTrue(npcs[0]->id("red fox") ||
            npcs[0]->id("white-tail deer") ||
            npcs[0]->id("chipmunk"));
        Spawned += npcs;
    }
}

/////////////////////////////////////////////////////////////////////////////
void ForesterAppearsAtTheShelter()
{
    object shelter = load_object(
        "/areas/argalen-keep/patrol-woods/12x3.c");

    move_object(Player, shelter);
    int residents = 0;
    foreach (object resident in all_inventory(shelter))
    {
        if (resident != Player)
        {
            ExpectTrue(member(inherit_list(resident),
                "/lib/realizations/npc.c") >= 0);
            ExpectTrue(resident->id("forester"));
            residents++;
            Harvested += ({ resident });
        }
    }
    ExpectEq(1, residents);
}

/////////////////////////////////////////////////////////////////////////////
void CoastalResidentsAppearAtTheirWorksites()
{
    mapping residents = ([
        "/areas/argalen-keep/patrol-coast/10x2.c":"farmer",
        "/areas/argalen-keep/patrol-coast/10x5.c":"fisherman"
    ]);

    foreach (string path, string name in residents)
    {
        object room = load_object(path);
        move_object(Player, room);
        int residentCount = 0;
        foreach (object resident in all_inventory(room))
        {
            if (resident != Player)
            {
                ExpectTrue(member(inherit_list(resident),
                    "/lib/realizations/npc.c") >= 0, path);
                ExpectTrue(resident->id(name), path);
                residentCount++;
                Harvested += ({ resident });
            }
        }
        ExpectEq(1, residentCount, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void PatrolCoastBlackberriesAreSeasonalAndHarvestable()
{
    object field = load_object(
        "/areas/argalen-keep/patrol-coast/10x2.c");
    object environment = getService("environment");
    int originalDay = environment->currentDay();
    move_object(Player, field);

    environment->setDay(20);
    ExpectFalse(objectp(field->harvestResource("blackberry", Player)));
    environment->setDay(260);
    object berry = field->harvestResource("blackberry", Player);
    ExpectTrue(objectp(berry));
    Harvested += ({ berry });
    environment->setDay(originalDay);
}

/////////////////////////////////////////////////////////////////////////////
void UpperGalleryOreRequiresAMiningTool()
{
    object room = load_object("/areas/minlach/surrounding/4x6.c");
    move_object(Player, room);
    ExpectSubStringMatch("iron ore",
        lower_case(room->harvestStatistics(Player)));
    ExpectSubStringMatch("pick axe",
        lower_case(room->harvestStatistics(Player)));
    ExpectFalse(objectp(room->harvestResource("iron ore", Player)));
}

/////////////////////////////////////////////////////////////////////////////
void VargathKeepHasASeparateNorthwestScreenplayRoute()
{
    object road = load_object("/areas/eledhel/north-road/0x2.c");
    object approach = load_object(
        "/areas/eledhel/vargath-keep/approach/0x2.c");
    object outpost = load_object(
        "/areas/eledhel/vargath-keep/approach/4x2.c");
    object caveEntry = load_object(
        "/areas/eledhel/vargath-keep/limestone-caves/0x0.c");
    object caveExit = load_object(
        "/areas/eledhel/vargath-keep/limestone-caves/4x2.c");
    object canyonEntry = load_object(
        "/areas/eledhel/vargath-keep/canyon/0x2.c");
    object trapdoor = load_object(
        "/areas/eledhel/vargath-keep/canyon/4x2.c");
    object keepEntry = load_object(
        "/areas/eledhel/vargath-keep/keep-interior/0x2.c");
    object audience = clone_object(
        "/areas/eledhel/vargath-keep/keep-interior/3x2.c");
    object boardCaveExit = load_object(
        "/areas/evenholt/limestone-caves/4x0.c");
    int foundVargath = 0;

    ExpectEq("/areas/eledhel/vargath-keep/approach/0x2.c",
        road->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/north-road/0x2.c",
        approach->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/vargath-keep/limestone-caves/0x0.c",
        outpost->getExitDirections()["default"]["down"]);
    ExpectEq("/areas/eledhel/vargath-keep/approach/4x2.c",
        caveEntry->getExitDirections()["default"]["up"]);
    ExpectEq("/areas/eledhel/vargath-keep/canyon/0x2.c",
        caveExit->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/vargath-keep/limestone-caves/4x2.c",
        canyonEntry->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/vargath-keep/keep-interior/0x2.c",
        trapdoor->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/vargath-keep/canyon/4x2.c",
        keepEntry->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/evenholt/grounds/24x2.c",
        boardCaveExit->getExitDirections()["default"]["east"]);

    foreach (object resident in all_inventory(audience))
    {
        if (function_exists("isRealizationOfNpc", resident) &&
            resident->isRealizationOfNpc())
        {
            if (resident->id("Vargath"))
            {
                foundVargath = 1;
            }
            Spawned += ({ resident });
        }
    }
    ExpectTrue(foundVargath);
    destruct(audience);
}

/////////////////////////////////////////////////////////////////////////////
void LinwaethRegionUsesTheBoundedSettlementFootprint()
{
    object region = load_object("/areas/linwaeth/region.c");

    ExpectTrue(objectp(region));
    ExpectEq(25, region->xDimension());
    ExpectEq(10, region->yDimension());
    ExpectEq(4, region->regionLevel());
}

/////////////////////////////////////////////////////////////////////////////
void LinwaethRoadConnectsToExistingSouthCountry()
{
    object road = load_object(
        "/areas/eledhel/south-rural-route-17/21x2.c");
    object entry = load_object("/areas/linwaeth/12x0.c");

    ExpectEq("/areas/linwaeth/12x0.c",
        road->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/south-rural-route-17/21x2.c",
        entry->getExitDirections()["default"]["north"]);
}

/////////////////////////////////////////////////////////////////////////////
void LinwaethBuildingsConnectToTheirInteriors()
{
    object inn = load_object("/areas/linwaeth/11x3.c");
    object smith = load_object("/areas/linwaeth/13x3.c");
    object commonRoom = clone_object(
        "/areas/linwaeth/looming-stag/0x1.c");
    object innDoor = clone_object(
        "/areas/linwaeth/looming-stag/2x1.c");
    object forge = clone_object("/areas/linwaeth/smithy/0x1.c");
    Harvested += ({ commonRoom, innDoor, forge });
    mapping commonRoomExitData = commonRoom->getExitDirections();
    mapping innDoorExitData = innDoor->getExitDirections();
    mapping forgeExitData = forge->getExitDirections();
    mapping commonRoomExits =
        mappingp(commonRoomExitData) &&
            mappingp(commonRoomExitData["default"]) ?
                commonRoomExitData["default"] : ([]);
    mapping innDoorExits = mappingp(innDoorExitData) &&
        mappingp(innDoorExitData["default"]) ?
            innDoorExitData["default"] : ([]);
    mapping forgeExits = mappingp(forgeExitData) &&
        mappingp(forgeExitData["default"]) ?
            forgeExitData["default"] : ([]);

    ExpectTrue(inn->isEnvironmentalElement("plank door"));
    ExpectTrue(smith->isEnvironmentalElement("plank door"));
    ExpectTrue(mappingp(commonRoomExitData));
    ExpectTrue(mappingp(innDoorExitData));
    ExpectTrue(mappingp(forgeExitData));
    ExpectEq("/areas/linwaeth/looming-stag/1x1.c",
        commonRoomExits["east"]);
    ExpectEq("/areas/linwaeth/11x3.c", innDoorExits["east"]);
    ExpectEq("/areas/linwaeth/13x3.c", forgeExits["west"]);
}

/////////////////////////////////////////////////////////////////////////////
void LinwaethResidentsAppearAtTheirWorksites()
{
    mapping residents = ([
        "/areas/linwaeth/looming-stag/0x1.c":"Rinna Inaeus",
        "/areas/linwaeth/smithy/0x1.c":"Johan",
        "/areas/linwaeth/12x1.c":"Edris",
        "/areas/eledhel/southwest-rural-four/10x3.c":"Edrin",
        "/areas/eledhel/southwest-rural-five/13x3.c":"Miren",
        "/areas/eledhel/southwest-rural-five/9x3.c":"Calen"
    ]);

    foreach (string path, string name in residents)
    {
        object room = clone_object(path);
        Harvested += ({ room });
        int foundResident = 0;
        move_object(Player, room);
        foreach (object resident in all_inventory(room))
        {
            if (function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                if (resident->id(name))
                {
                    foundResident = 1;
                }
                Spawned += ({ resident });
            }
        }
        ExpectTrue(foundResident, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void SouthernCoastRoadConnectsLinwaethAndAnor()
{
    mapping links = ([
        "/areas/linwaeth/12x9.c":
            (["south": "/areas/eledhel/south-coast-one/12x0.c"]),
        "/areas/eledhel/south-coast-one/12x9.c":
            (["south": "/areas/eledhel/south-coast-two/12x0.c"]),
        "/areas/eledhel/south-coast-two/12x9.c":
            (["south": "/areas/anor/12x0.c"]),
        "/areas/anor/12x0.c":
            (["north": "/areas/eledhel/south-coast-two/12x9.c"])
    ]);

    foreach (string path, mapping expectedExits in links)
    {
        object room = load_object(path);
        mapping exits = room->getExitDirections()["default"];
        foreach (string direction, string target in expectedExits)
        {
            ExpectEq(target, exits[direction],
                sprintf("%s %s exit", path, direction));
        }
    }

    object firstCoast = load_object(
        "/areas/eledhel/south-coast-one/region.c");
    object secondCoast = load_object(
        "/areas/eledhel/south-coast-two/region.c");
    object anor = load_object("/areas/anor/region.c");
    ExpectEq(25, firstCoast->xDimension());
    ExpectEq(10, firstCoast->yDimension());
    ExpectEq(25, secondCoast->xDimension());
    ExpectEq(10, secondCoast->yDimension());
    ExpectEq(25, anor->xDimension());
    ExpectEq(10, anor->yDimension());
    ExpectEq(5, firstCoast->regionLevel());
    ExpectEq(6, secondCoast->regionLevel());
    ExpectEq(7, anor->regionLevel());
}

/////////////////////////////////////////////////////////////////////////////
void SouthernCoastAndAnorResidentsAppearAtTheirWorksites()
{
    mapping residents = ([
        "/areas/eledhel/south-coast-one/14x2.c": "Mairen",
        "/areas/eledhel/south-coast-one/10x6.c": "Tiriel",
        "/areas/anor/12x1.c": "Cailen",
        "/areas/anor/15x6.c": "Aderyn",
        "/areas/anor/10x3.c": "Elen"
    ]);

    foreach (string path, string name in residents)
    {
        object room = clone_object(path);
        Harvested += ({ room });
        move_object(Player, room);
        int foundResident = 0;
        foreach (object resident in all_inventory(room))
        {
            if (resident != Player &&
                function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                if (resident->id(name))
                {
                    foundResident = 1;
                }
                Spawned += ({ resident });
            }
        }
        ExpectTrue(foundResident, path);
    }
}

/////////////////////////////////////////////////////////////////////////////
void SouthernBackcountryEncountersMatchTheirRegionalLevels()
{
    mapping encounterRooms = ([
        "/areas/eledhel/south-coast-one/region.c":
            (["room": "10x5", "level": 5]),
        "/areas/eledhel/south-coast-two/region.c":
            (["room": "15x5", "level": 6]),
        "/areas/eledhel/south-coast-two/cove-cave/region.c":
            (["room": "1x2", "level": 6])
    ]);

    foreach (string regionPath, mapping details in encounterRooms)
    {
        object region = load_object(regionPath);
        object room = region->getEnvironment(details["room"]);
        move_object(Player, room);
        int encounters = 0;
        foreach (object encounter in all_inventory(room))
        {
            if (encounter != Player &&
                function_exists("isRealizationOfMonster", encounter) &&
                encounter->isRealizationOfMonster())
            {
                int level = encounter->effectiveLevel();
                ExpectTrue(level >= details["level"] - 2 &&
                    level <= details["level"] + 2,
                    sprintf("%s %s encounter level %d", regionPath,
                        details["room"], level));
                encounters++;
                Spawned += ({ encounter });
            }
        }
        ExpectTrue(encounters >= 1 && encounters <= 3,
            sprintf("%s %s has %d encounters", regionPath,
                details["room"], encounters));
        destruct(region);
    }
}
