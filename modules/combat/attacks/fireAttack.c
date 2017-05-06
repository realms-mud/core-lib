inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("fire");
    addHitDictionary(({
        "scorch", "immolate", "blast", "burn", "torch", "ignite", "singe",
        "roast", "melt", "broil", "char" }));

    addSimileDictionary(({
        "with a stream of flame", "with flaming tendrils", "with a pillar of " +
        "flame", "with a roaring conflagration" }));
        
    addMissMessage("##AttackerName## ##Infinitive::produce## a tiny mote of "
            "inconsequential flame.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## " +
            "##SimileDictionary##.", "1-50");
}



