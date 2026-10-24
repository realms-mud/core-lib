//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkCombatComparisonFixture.c";

/////////////////////////////////////////////////////////////////////////////
void LevelFiftyReferenceUsesNaturalBudgetsAndLegalCombat()
{
    CompareBuild("Aegis Guard", "swords", "katana",
        ({ "/guilds/aegis-guard/sword-attacks.c" }), 50);
}
