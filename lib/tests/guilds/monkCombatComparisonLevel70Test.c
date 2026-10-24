//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/support/guilds/monkCombatComparisonFixture.c";

/////////////////////////////////////////////////////////////////////////////
void KatanaSpecialistUsesNaturalBudgetsAndLegalCombat()
{
    CompareBuild("monk", "katana", "katana",
        ({ "/guilds/monk/katana.c" }), 70);
}

/////////////////////////////////////////////////////////////////////////////
void OdachiSpecialistUsesNaturalBudgetsAndLegalCombat()
{
    CompareBuild("monk", "odachi", "odachi",
        ({ "/guilds/monk/odachi.c" }), 70);
}

/////////////////////////////////////////////////////////////////////////////
void ArcherySpecialistUsesNaturalBudgetsAndLegalCombat()
{
    CompareBuild("monk", "archery", "long bow",
        ({ "/guilds/monk/archery.c" }), 70);
}

/////////////////////////////////////////////////////////////////////////////
void FighterReferenceUsesNaturalBudgetsAndLegalCombat()
{
    CompareBuild("fighter", "blades", "katana",
        ({ "/guilds/fighter/blade-attacks.c" }), 70);
}

/////////////////////////////////////////////////////////////////////////////
void RangerReferenceUsesNaturalBudgetsAndLegalCombat()
{
    CompareBuild("ranger", "archery", "long bow",
        ({ "/guilds/ranger/archery.c" }), 70);
}
