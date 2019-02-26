//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void CurrentTimeDayANdYearCorrectlyDisplayed()
{
    ExpectEq(661, Dictionary->currentTime());
    ExpectEq(92, Dictionary->currentDay());
    ExpectEq(1, Dictionary->currentYear());

    Dictionary->advanceTime(345);
    ExpectEq(1006, Dictionary->currentTime());
    ExpectEq(92, Dictionary->currentDay());
    ExpectEq(1, Dictionary->currentYear());
}

/////////////////////////////////////////////////////////////////////////////
void SettingTimeOfDayAltersCurrentTime()
{
    ExpectEq(661, Dictionary->currentTime());
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
