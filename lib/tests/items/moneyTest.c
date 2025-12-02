//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Money;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Money = clone_object("/lib/items/money");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Money);
}

/////////////////////////////////////////////////////////////////////////////
void MoneyWithoutValueDefaultsShortToOneCoin()
{
    Money.set("value", 1);
    ExpectEq("A coin", Money.query("short"));
}

/////////////////////////////////////////////////////////////////////////////
void MoneyWithValueReturnsProperDescription()
{
    Money.set("value", 126);
    ExpectEq("A pile of 126 coins", Money.query("short"));
}
