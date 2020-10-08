//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/combat/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        ::reset(arg);
        setDamageType("sonic");
        addHitDictionary(({
            "blast", "slam", "flatten", "crush", "ram", "crash", "hammer" }));

        addSimileDictionary(({
            "with a wave of sonic energy", "with shrieking whips of sonic waves",
            "with a thunderous BOOM of sonic energy" }));

        addMissMessage("##AttackerName## ##Infinitive::cover## "
            "##AttackerPossessive## ears and ##Infinitive::scream##,"
            "'LA LA LA LA LA!'");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary##.", "1-150");
    }
}
