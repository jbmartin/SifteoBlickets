IconAssets = group{ quality=10.00 }
Icon = image{ "assets/nyu-logo.png"}

BootstrapAssets = group{ quality=9.0 }

BlackTile = image{ "assets/black.png", pinned=true }

Bars = {
	image{ "assets/bar_top.png", pinned=true },
	image{ "assets/bar_left.png", pinned=true },
	image{ "assets/bar_bottom.png", pinned=true },
	image{ "assets/bar_right.png", pinned=true }
}

Set1IdenticalObjects = image{{ "assets/green_rect.png", "assets/green_rect.png",
                               "assets/green_rect.png", "assets/green_rect.png" }}
Set2SameColorDifferentShape = image{{ "assets/green_rect.png", "assets/green_sq.png",
                                      "assets/green_rounded_rect.png", "assets/green_oval.png" }}
Set3SameShapeDifferentColors = image{{ "assets/green_rect.png", "assets/red_rect.png",
                                       "assets/blue_rect.png", "assets/yellow_rect.png" }}
Set4DifferentColorsAndShapes = image{{ "assets/green_sq.png", "assets/blue_oval.png",
                                       "assets/red_tri.png", "assets/yellow_rounded_rect.png" }}
Set5SameShapeConflictsOnColor = image{{ "assets/green_rounded_rect.png", "assets/green_rounded_rect.png",
                                        "assets/red_rounded_rect.png", "assets/red_rounded_rect.png" }}
Set6SameColorConflictsOnShape = image{{ "assets/green_rounded_rect.png", "assets/green_rounded_rect.png",
                                        "assets/green_sq.png", "assets/green_sq.png", }}
Set7ConflictsOnShapeAndColor = image{{ "assets/blue_rect.png", "assets/blue_rect.png",
                                       "assets/green_sq.png", "assets/green_sq.png" }}


Backgrounds = image{{ "assets/bg_sleep_zoom.png", "assets/bg_wake_zoom.png" }}

SfxAttach = sound{ "assets/attach.raw" }
SfxSong = sound{ "assets/fur_elise_10s_clip.wav"}
SfxDetach = sound{ "assets/detach.raw" }
SfxConnect = sound{ "assets/connect.raw" }
