/*
 * GStreamer
 * Copyright (C) 2005 Thomas Vander Stichele <thomas@apestaart.org>
 * Copyright (C) 2005 Ronald S. Bultje <rbultje@ronald.bitfreak.net>

 * Copyright (C) 2023 Teledyne e2V, Author : Loic Chevallier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef __GST_FPSCOUNTER_H__
#define __GST_FPSCOUNTER_H__

#include <gst/gst.h>

G_BEGIN_DECLS

/* #defines don't like whitespacey bits */
#define GST_TYPE_FPSCOUNTER \
  (gst_fps_counter_get_type())
#define GST_FPSCOUNTER(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_FPSCOUNTER,GstfpsCounter))
#define GST_FPSCOUNTER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_FPSCOUNTER,GstfpsCounterClass))
#define GST_IS_FPSCOUNTER(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_FPSCOUNTER))
#define GST_IS_FPSCOUNTER_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_FPSCOUNTER))

typedef struct _GstfpsCounter      GstfpsCounter;
typedef struct _GstfpsCounterClass GstfpsCounterClass;
    static struct timeval start, end;
struct _GstfpsCounter
{
  GstElement element;

  GstPad *sinkpad, *srcpad;

  gboolean timestamp;
  gboolean silent;
  gint framerate
};

struct _GstfpsCounterClass 
{
  GstElementClass parent_class;
};

GType gst_fps_counter_get_type (void);

G_END_DECLS

#endif /* __GST_FPSCOUNTER_H__ */
