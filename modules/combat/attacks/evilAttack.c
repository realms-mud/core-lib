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
        setDamageType("evil");
        damagesEthereal();
        addHitDictionary(({
            "eviscerate", "slam", "menace", "flatten", "crush", "slam",
            "crash", "gut", "rip", "shred", "gouge" }));

        addSimileDictionary(({
            "with a bolt of sickly green energy", "with tendrils of black energy",
            "and demonic howls are heard in the air" }));

        addMissMessage("##AttackerName## ##Infinitive::look## very menacing! But "
            "that's about it.");

        addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## " +
            "##SimileDictionary##.", "1-150");
    }
}



