/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mbed-drivers/mbed.h"

#include "uif-matrixlcd/MatrixLCD.h"
#include "UIFramework/UIFramework.h"
#include "UIFramework/UITableView.h"

#include "wrd-myotest-library-feeder/MyotestLibraryFeeder.h"
#include "uif-ui-myotest-step-analysis-wrd/StepAnalysisTable.h"

static uif::MatrixLCD lcd;
static SharedPointer<UIFramework> uiFramework;

void app_start(int, char *[])
{
    MyotestLibraryFeeder::Instance()->start();

    /**************************************************************************
    **************************************************************************/

    SharedPointer<UIView::Array> table(new StepAnalysisTable());
    SharedPointer<UIView> view(new UITableView(table));
    view->setWidth(128);
    view->setHeight(128);
    view->setInverse(true);

    // UI framework
    uiFramework = SharedPointer<UIFramework>(new UIFramework(lcd, view));
}
