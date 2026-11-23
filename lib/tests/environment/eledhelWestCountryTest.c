//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({ "RunSelectedTests" }));
}

void RunSelectedTests()
{
    runSelectedTests(({
        "WestRuralEntryTrailIsAuthoredAndDecorated",
        "WestRuralEntryHasNoncombatWildlife",
        "ForesterAppearsAtTheShelter",
        "CoastalResidentsAppearAtTheirWorksites",
        "PatrolCoastBlackberriesAreSeasonalAndHarvestable",
        "UpperGalleryOreRequiresAMiningTool",
        "VargathKeepHasASeparateNorthwestScreenplayRoute"
    }));
}
