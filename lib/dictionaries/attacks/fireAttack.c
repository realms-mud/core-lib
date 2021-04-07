//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/attacks/baseAttack.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setDamageType("fire");
    damagesEthereal();
    addHitDictionary(({
        "scorch", "immolate", "blast", "burn", "torch", "ignite", "singe",
        "roast", "melt", "broil", "char" }));

    addSimileDictionary(({
        "with a stream of flame", "with flaming tendrils", "with a pillar of " +
        "flame", "with a roaring conflagration" }));

    addMissMessage("##AttackerName## ##Infinitive::produce## a tiny mote of "
        "inconsequential flame.");

    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## " +
        "##SimileDictionary##.", "1-150");
}
