//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = getService("environment");
    Service.setYear(1);
    Service.setDay(92);
    Service.timeOfDay("noon");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void CurrentTimeDayAndYearCorrectlyDisplayed()
{
    ExpectEq(660, Service.currentTime());
    ExpectEq(92, Service.currentDay());
    ExpectEq(1, Service.currentYear());

    Service.advanceTime(345);
    ExpectEq(1005, Service.currentTime());
    ExpectEq(92, Service.currentDay());
    ExpectEq(1, Service.currentYear());
}

/////////////////////////////////////////////////////////////////////////////
void SettingTimeOfDayAltersCurrentTime()
{
    ExpectEq(660, Service.currentTime());
    ExpectEq("noon", Service.timeOfDay());

    Service.timeOfDay("afternoon");
    ExpectEq(990, Service.currentTime());
    ExpectEq("afternoon", Service.timeOfDay());
}

/////////////////////////////////////////////////////////////////////////////
void AdvancingTimePastEndOfDayIncrementsDayAndRollsTime()
{
    Service.timeOfDay("night");
    ExpectEq(92, Service.currentDay());

    Service.advanceTime(60);
    ExpectEq(0, Service.currentTime());
    ExpectEq("midnight", Service.timeOfDay());
    ExpectEq(93, Service.currentDay());
}

/////////////////////////////////////////////////////////////////////////////
void AdvancingTimePastSeasonIncrementsSeason()
{
    Service.setDay(91);
    ExpectEq(91, Service.currentDay());
    ExpectEq("spring", Service.season());

    Service.advanceTime(1440);
    ExpectEq(92, Service.currentDay());
    ExpectEq("summer", Service.season());
}

/////////////////////////////////////////////////////////////////////////////
void AdvancingTimePastYearIncrementsYearAndResetsSeason()
{
    Service.setDay(364);
    ExpectEq(364, Service.currentDay());
    ExpectEq("winter", Service.season());
    ExpectEq(1, Service.currentYear());

    Service.advanceTime(1440);
    ExpectEq(0, Service.currentDay());
    ExpectEq("spring", Service.season());
    ExpectEq(2, Service.currentYear());
}

/////////////////////////////////////////////////////////////////////////////
void MoonPhasesAreDisplayedCorrectly()
{
    ExpectEq("first quarter", Service.moonPhase());

    Service.setDay(2);
    ExpectEq("waxing crescent", Service.moonPhase());
}

/////////////////////////////////////////////////////////////////////////////
void MoonPhasesRollOverToNewMoon()
{
    Service.setDay(362);
    ExpectEq("waning crescent", Service.moonPhase());

    Service.setDay(363);
    ExpectEq("new moon", Service.moonPhase());
}
