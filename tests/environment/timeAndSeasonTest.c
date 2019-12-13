//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    Dictionary->setYear(1);
    Dictionary->setDay(92);
    Dictionary->timeOfDay("noon");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CurrentTimeDayANdYearCorrectlyDisplayed()
{
    ExpectEq(660, Dictionary->currentTime());
    ExpectEq(92, Dictionary->currentDay());
    ExpectEq(1, Dictionary->currentYear());

    Dictionary->advanceTime(345);
    ExpectEq(1005, Dictionary->currentTime());
    ExpectEq(92, Dictionary->currentDay());
    ExpectEq(1, Dictionary->currentYear());
}

/////////////////////////////////////////////////////////////////////////////
void SettingTimeOfDayAltersCurrentTime()
{
    ExpectEq(660, Dictionary->currentTime());
    ExpectEq("noon", Dictionary->timeOfDay());

    Dictionary->timeOfDay("afternoon");
    ExpectEq(990, Dictionary->currentTime());
    ExpectEq("afternoon", Dictionary->timeOfDay());
}

/////////////////////////////////////////////////////////////////////////////
void AdvancingTimePastEndOfDayIncrementsDayAndRollsTime()
{
    Dictionary->timeOfDay("night");
    ExpectEq(92, Dictionary->currentDay());

    Dictionary->advanceTime(60);
    ExpectEq(0, Dictionary->currentTime());
    ExpectEq("midnight", Dictionary->timeOfDay());
    ExpectEq(93, Dictionary->currentDay());
}

/////////////////////////////////////////////////////////////////////////////
void AdvancingTimePastSeasonIncrementsSeason()
{
    Dictionary->setDay(91);
    ExpectEq(91, Dictionary->currentDay());
    ExpectEq("spring", Dictionary->season());

    Dictionary->advanceTime(1440);
    ExpectEq(92, Dictionary->currentDay());
    ExpectEq("summer", Dictionary->season());
}

/////////////////////////////////////////////////////////////////////////////
void AdvancingTimePastYearIncrementsYearAndResetsSeason()
{
    Dictionary->setDay(364);
    ExpectEq(364, Dictionary->currentDay());
    ExpectEq("winter", Dictionary->season());
    ExpectEq(1, Dictionary->currentYear());

    Dictionary->advanceTime(1440);
    ExpectEq(0, Dictionary->currentDay());
    ExpectEq("spring", Dictionary->season());
    ExpectEq(2, Dictionary->currentYear());
}

/////////////////////////////////////////////////////////////////////////////
void MoonPhasesAreDisplayedCorrectly()
{
    ExpectEq("first quarter", Dictionary->moonPhase());

    Dictionary->setDay(2);
    ExpectEq("waxing crescent", Dictionary->moonPhase());
}

/////////////////////////////////////////////////////////////////////////////
void MoonPhasesRollOverToNewMoon()
{
    Dictionary->setDay(362);
    ExpectEq("waning crescent", Dictionary->moonPhase());

    Dictionary->setDay(363);
    ExpectEq("new moon", Dictionary->moonPhase());
}
