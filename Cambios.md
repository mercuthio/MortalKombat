CAMBIOS FUERA DE LA RAMA MAIN

# Liu Kang
Volver a copiar entrero
 
# Animation.h
99. if (n_of_flagged_frames > 0 && this_flagged_frame < n_of_flagged_frames)

# Character.h
111->219. CheckAnimation()
271->300. DoAnimation()
302->310. EndAnimation()

=DETALLADO=
115. cout (DEBUG)
163. crouching = true
293. !hasFLag()
303. cout (DEBUG)
306->308. on_air crouching punching = false

# Definitions
92. bool hasFlag(AnimationType anim)