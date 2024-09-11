#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <vector>
#include <cmath>

#include "../core/waste_water_model.hpp"

namespace hydro
{
    class UI : public Fl_Widget
    {
    private:
        WasteWaterModel model;
    public:
        UI(uint32_t& x, uint32_t& y, uint32_t& w, uint32_t& h, WasteWaterModel& mod)
            : Fl_Widget (x, y, w, h) 
        {
            model = std::move(mod);
        }

        void draw () override {
            fl_color (FL_WHITE);
            fl_rectf(x(), y(), w(), h());

            fl_color (FL_BLACK);

            for (const auto& pipe : model.pipes) {
                // fl_line ()
            }
        }
        ~UI();
    };
    
} // namespace hydro


#endif