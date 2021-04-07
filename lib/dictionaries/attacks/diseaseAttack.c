//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("disease");
    addHitDictionary(({
        "infect", "beplague", "inject", "inflict", "impart", "defile",
        "corrupt", "assail" }));

    addSimileDictionary(({
        "with a horrible disease", "with a horrfying sickness",
        "with a nasty infection", "with a debilitating illness" }));

    addMissMessage("##AttackerName## ##Infinitive::sputter## something about"
        " icky germs.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##. Eeew.",
        "1-150");
}
