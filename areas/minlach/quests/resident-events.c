//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping assignments = ([
    "cargo":({ "fennel", "short-weight-cargo",
        "settleCargoCosts", "recordCargoDamage" }),
    "carter":({ "roven", "last-waymarker",
        "arrangeCarterWagon", "requestCarterWatch" }),
    "beacon":({ "neris", "false-harbor-light",
        "protectHarborCrew", "openHarborInquiry" }),
    "net":({ "sella", "net-for-winter",
        "arrangeNetRepair", "arrangeNetCredit" }),
    "witness":({ "tristan", "constables-witness",
        "clearAccusedTraveler", "keepWarehouseInquiry" }),
    "stream":({ "edda", "roots-by-the-stream",
        "arrangeDitchRepair", "arrangeCleanWater" }),
    "tower":({ "orlen", "watchtowers-names",
        "preserveTowerRecords", "recordTowerOwnership" }),
    "quarry":({ "harl", "flooded-workings",
        "sendQuarryRecovery", "requestQuarrySupport" }),
    "road":({ "basil", "road-measure",
        "reportRoadMeasures", "acceptRoadRepair", "reserveStores" }),
    "seam":({ "harl", "safe-seam",
        "keepSeamClosed", "allowLimitedSurvey" }),
    "watch":({ "bren", "place-at-the-wall",
        "offerCivilWatch", "requestWatchTraining" }),
    "woods":({ "maelin", "woodland-boundary",
        "mediateWoodlandCosts", "recordWoodlandBoundary" }),
    "lodging":({ "roven", "warm-room",
        "arrangeLodgingWork", "arrangeLodgingAid" }),
    "courier":({ "tristan", "couriers-packet",
        "correctCourierRoute", "investigateCourierRoute" })
]);

/////////////////////////////////////////////////////////////////////////////
public varargs int receiveEvent(object resident, string event, object player)
{
    int handled = 0;
    if (objectp(player) && objectp(resident) &&
        environment(player) == environment(resident))
    {
        foreach (string key, string *assignment in assignments)
        {
            string source = "/areas/minlach/characters/" +
                assignment[0] + "/" + assignment[0] + ".c";
            string quest = "/areas/minlach/quests/" +
                assignment[1] + ".c";
            if (program_name(resident) == source &&
                event == "minlachBegin" + capitalize(key))
            {
                handled = 1;
                if (player->beginQuest(quest))
                {
                    player->onStateChanged(load_object(quest),
                        player->questState(quest));
                    tell_object(player, "Your quest journal now records " +
                        load_object(quest)->name() + ".\n");
                }
                else
                {
                    tell_object(player, "That assignment is already in "
                        "your journal or is not available to you.\n");
                }
            }
            else if (program_name(resident) == source &&
                member(assignment[2..], event) >= 0)
            {
                handled = 1;
                if (!player->questIsActive(quest) ||
                    !load_object(quest)->receiveEvent(player, event))
                {
                    tell_object(player, "You must complete the "
                        "investigation before settling this assignment.\n");
                }
            }
        }
    }
    return handled;
}
